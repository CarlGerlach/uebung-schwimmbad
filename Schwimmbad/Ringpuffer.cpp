#include "Ringpuffer.h"

Ringpuffer::Ringpuffer(int size)
{
	size = 10;
}

void Ringpuffer::addValue(Messung* ini_m)
{
    // 1?? Prüfe, ob noch ein freier Platz vorhanden ist
    for (int i = 0; i < 10; i++)
    {
        if (values[i] == nullptr)
        {
            values[i] = ini_m; // einfügen
            return;            // fertig
        }
    }

    // 2?? Wenn Puffer voll: finde die älteste Messung
    int oldestIndex = 0;
    for (int i = 1; i < 10; i++)
    {
        // string-Vergleich funktioniert, weil Format "YYYY-MM-DD HH:MM:SS"
        if (values[i]->getDatum() < values[oldestIndex]->getDatum())
        {
            oldestIndex = i;
        }
    }

    // 3?? Überschreibe die älteste Messung
    values[oldestIndex] = ini_m;
}