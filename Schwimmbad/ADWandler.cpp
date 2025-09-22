#include "ADWandler.h"
#include "Serial.h"
#include <iostream>

using namespace std;


ADWandler::ADWandler(int i)
{
	serial = new Serial("COM1",9600,1,1,1);
}


ADWandler::~ADWandler(void)
{
}

int ADWandler::liesWert()
{
	if (!serial->open())
	{
		return -99;
	}

	int wert = 0;

	// ToDo 1. Aufgabe

	serial->setRTS(0);
	serial->setDTR(0);
	

	for(int i = 0; i < 8; i++)
	{	
		

		serial->setRTS(1);
		serial->setRTS(0);
		bool tmp = serial->isCTS();
		wert = wert + (static_cast<int>(pow(2, i))); //Wert + 2 Hoch i -> macht Sinn
	}

	serial->setDTR(1);



	
	return wert;
	serial->close();
}
