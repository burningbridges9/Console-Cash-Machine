#include "stdafx.h"
#include "Machine.h"


void Machine::Work(string &S)
{
	cmatch result;

	if (S[0] == '+')
	{
		S.erase(0, 2);
		regex regular("([A-Z]{3}) (\\d{1,6}) (\\d{1,10})");
		if (regex_match(S.c_str(), result, regular))
		{
			string currency = result[1];
			int value = stoi(result[2]);
			int num = stoi(result[3]);
			if (currency == "USD")
			{
				DV.Add(value, num);
			}
			if (currency == "RUR")
			{
				RV.Add(value, num);
			}

		}
		else
		{
			cout<<"ERROR\n";
		}
	}
	if (S[0] == '-')
	{
		string currency = S.substr(2, 3);
		S.erase(0, 2);
		regex regular("([A-Z]{3}) (\\d{1,10})");
		if (regex_match(S.c_str(), result, regular))
		{
			string currency = result[1];
			int amount = stoi(result[2]);
			if (currency == "USD")
			{
				DV.Get(amount);
			}

			if (currency == "RUR")
			{
				RV.Get(amount);
			}
		}
		else
		{
			cout << "ERROR\n";
		}
	}
	if (S[0] == '?')
	{
		DV.Show();
		RV.Show();
	}
}

void Machine::EndlessWork()
{
	string S;
	while (true)
	{
		getline(cin, S);
		Work(S);
	}
}

Machine::Machine()
{
	cout << "example use for USD:" << endl;
	cout << "+ USD 10 10" << endl;
	cout << "- USD 100" << endl;
	cout << "?" << endl;

	cout << "example use for RUR:" << endl;
	cout << "+ RUR 10 10" << endl;
	cout << "- RUR 100" << endl;
	cout << "?" << endl;
}


Machine::~Machine()
{
}
