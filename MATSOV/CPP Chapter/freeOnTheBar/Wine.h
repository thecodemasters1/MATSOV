#ifndef WINE_H
#define WINE_H

#include <iostream>
#include "Drink.h"
using namespace std;

class Wine: public Drink
{
public:
	Wine(const char* name, int wineYear, int servingTemp);
	void prepare() const;

protected:
	int m_wineYear;
	int m_servingTemp;
};

#endif
