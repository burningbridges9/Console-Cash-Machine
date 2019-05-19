#pragma once
#include <string>
#include <map>
#include <iostream>
#include <array>
using namespace std;
class DollarValue
{
	string NameVal;
	map<int, int> ValNum;
public:
	DollarValue();
	void Show();
	void Add(int Value, int Number);
	void Get(int amount);
	~DollarValue();
};

