#pragma once
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

class Messung
{
private:
	string datumUhrzeit;
	int werte[3] = { 0 };

public:
	Messung();
	Messung(int temp1, int temp2, int temp3);
	~Messung(void);
	
	string getDatum();
	


};

