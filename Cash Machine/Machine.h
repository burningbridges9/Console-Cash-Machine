#pragma once
#include <string>
#include <iostream>
#include "DollarValue.h"
#include "RubleValue.h"
#include <regex>
using namespace std;
class Machine
{
private:
	DollarValue DV;
	RubleValue RV;
public:
	void Work(string &S);
	void EndlessWork();
	Machine();
	~Machine();
};

