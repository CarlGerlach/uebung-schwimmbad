#pragma once
#include <list>
#include "Messung.h"


class Ringpuffer
{
private:
	int size;
	Messung* values[10] = {};

public:
	Ringpuffer(int size);

	void addValue(Messung* ini_m);



};

