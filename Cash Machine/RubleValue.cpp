#include "stdafx.h"
#include "RubleValue.h"


RubleValue::RubleValue()
{
	NameVal = "RUR";
	ValNum = { { 1,0 },{ 10,0 },{ 100 ,0 },{ 1000 ,0 },
	{ 5,0 },{ 50,0 },{ 500,0 },{ 5000,0 } };
}

void RubleValue::Show()
{
	bool f = false;
	for (auto it = ValNum.begin(); it != ValNum.end(); ++it)
	{
		if (it->second != 0)
		{
			f = true;
			cout << NameVal << " " << it->first << " " << it->second << endl;
		}
	}
	if (f == false)
	{
		cout << NameVal << " is empty" << endl;
	}
}

void RubleValue::Add(int Value, int Number)
{
	if (ValNum.find(Value) == ValNum.end())
	{
		cout << "ERROR" << endl;
	}
	else
	{
		auto it = ValNum.find(Value);
		it->second += Number;
		cout << "OK" << endl;
	}
}

void RubleValue::Get(int amount)
{

	int CurrentSum = 0;
	int tempAmount = amount;
	map<int, int> used = { { 1,0 },{ 10,0 },{ 100 ,0 },{ 1000 ,0 },{ 5,0 },{ 50,0 },{ 500,0 },{ 5000,0 } };

	for (auto it = ValNum.begin(); it != ValNum.end(); ++it)
	{
		CurrentSum += it->first*it->second;
	}
	if (CurrentSum < amount)
	{
		cout << "ERROR" << endl;
	}
	else
	{
		if (CurrentSum == amount)
		{
			auto usedIter = used.begin();
			for (auto it = ValNum.begin(); it != ValNum.end(); ++it)
			{
				usedIter->second = it->second;
				tempAmount -= it->first*it->second;
				it->second = 0;
				++usedIter;
			}
		}
		else
		{
			auto usedIter = used.rbegin();
			for (auto it = ValNum.rbegin(); it != ValNum.rend(); ++it)
			{
				if (it->second == 0)
				{
					++usedIter;
					continue;
				}
				else
				{
					while (it->second != 0)
					{
						if (it->first > tempAmount)
						{
							break;
						}
						else
						{
							tempAmount -= it->first;
							--it->second;

							usedIter->second++;
						}
					}
					++usedIter;
				}

			}
		}

		if (tempAmount != 0)
		{
			cout << "ERROR" << endl;
		}
		else
		{
			for (auto usedIter = used.rbegin(); usedIter != used.rend(); ++usedIter)
			{
				if (usedIter->second != 0)
					cout << usedIter->first << " " << usedIter->second << endl;
			}
			cout << "OK" << endl;
		}
	}
}


RubleValue::~RubleValue()
{
}
