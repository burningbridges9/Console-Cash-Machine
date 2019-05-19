// Cash Machine.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "DollarValue.h"
#include "Machine.h"
#include <iostream>
using namespace std;
int main()
{
	/*DollarValue DV;
	DV.Show();
	DV.Add(1, 100);
	DV.Show();*/
	Machine m;
	m.EndlessWork();
	system("PAUSE");
    return 0;
}

