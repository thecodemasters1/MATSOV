#include "WhiteWine.h"

const int WHITEWINE_SERVINGTEMP = 4;

WhiteWine::WhiteWine(const char* name, int wineYear) : Wine(name, wineYear, WHITEWINE_SERVINGTEMP)
{
}
