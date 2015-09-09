#include "RedWine.h"

const int REDWINE_SERVINGTEMP = 16;

RedWine::RedWine(const char* name, int wineYear) : Wine(name, wineYear, REDWINE_SERVINGTEMP)
{
}
