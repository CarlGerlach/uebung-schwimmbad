#include "Messung.h"
#include <ctime>
#include <iomanip>
#include <sstream>

Messung::Messung(int temp1, int temp2, int temp3)
{

	werte[0] = temp1;
	werte[1] = temp2;
	werte[2] = temp3;


    // aktuelles Datum + Uhrzeit als String
    time_t jetzt = time(0);
    tm* lokal = localtime(&jetzt);

    stringstream ss;
    ss << 1900 + lokal->tm_year << "-"
        << setfill('0') << setw(2) << 1 + lokal->tm_mon << "-"
        << setw(2) << lokal->tm_mday << " "
        << setw(2) << lokal->tm_hour << ":"
        << setw(2) << lokal->tm_min << ":"
        << setw(2) << lokal->tm_sec;

    datumUhrzeit = ss.str();
}

string Messung::getDatum()
{
    return datumUhrzeit;
}
