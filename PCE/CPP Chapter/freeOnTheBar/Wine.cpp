#include "Wine.h"

Wine::Wine(const char* name, int wineYear, int servingTemp) : Drink(name)
{
	m_wineYear = wineYear;
	m_servingTemp = servingTemp;
}

void Wine::prepare() const
{
	cout << m_name << ", " << m_wineYear << " - \nCarfully open the bottle. Pour to a glass at a serving temperature of " << m_servingTemp << " degrees celsius.";
}
