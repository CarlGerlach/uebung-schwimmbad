#include <chrono>
#include <thread>
#include "Steuerung.h"
#include <iostream>

using namespace std;

Steuerung::Steuerung(int ini_sollTemp)
{
	sollTemp = ini_sollTemp;
	intervall = 10;
	alarm = "green";

	for (int i = 0; i < 3; i++)
	{
		wandler[i] = new ADWandler(i);
	}

	heizung = new Heizung();

}

int Steuerung::inCelsius(int d)
{
	int c = 0;
	if (d <= 255 && d >= 210)
	{
		c = -1 / 3 * d + 90;
	}
	else if (d < 210 && d >= 190)
	{
		c = -d + 230;
	}
	else
	{
		return 0;
	}
	
	
	
	return c;
}
