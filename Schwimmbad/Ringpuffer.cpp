#include "Ringpuffer.h"

Ringpuffer::Ringpuffer(int size)
{
	size = 10;
}

void Ringpuffer::addValue(Messung* ini_m)
{
    // 1?? Pr�fe, ob noch ein freier Platz vorhanden ist
    for (int i = 0; i < 10; i++)
    {
        if (values[i] == nullptr)
        {
            values[i] = ini_m; // einf�gen
            return;            // fertig
        }
    }

    // 2?? Wenn Puffer voll: finde die �lteste Messung
    int oldestIndex = 0;
    for (int i = 1; i < 10; i++)
    {
        // string-Vergleich funktioniert, weil Format "YYYY-MM-DD HH:MM:SS"
        if (values[i]->getDatum() < values[oldestIndex]->getDatum())
        {
            oldestIndex = i;
        }
    }

    // 3?? �berschreibe die �lteste Messung
    values[oldestIndex] = ini_m;
}