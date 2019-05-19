#pragma once
#include <string>
#include <map>
#include <iostream>
using namespace std;
class RubleValue
{
private:
	string NameVal;
	map<int, int> ValNum;
public:
	RubleValue();
	void Show();
	void Add(int Value, int Number);
	void Get(int amount);
	~RubleValue();
};

