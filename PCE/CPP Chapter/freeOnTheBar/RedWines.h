#include "RedWine.h"

class ChadeauMargot: public RedWine
{
public:
	ChadeauMargot(int wineYear);
};

class Chianti: public RedWine
{
public:
	Chianti(int wineYear);
};

class YardenCabarnetSauvignon: public RedWine
{
public:
	YardenCabarnetSauvignon(int wineYear);
};

class YardenHermon: public RedWine
{
public:
	YardenHermon(int wineYear);
};
