#include "Beer.h"

Beer::Beer(const char* name) : Drink(name)
{
}

void Beer::prepare() const
{
	cout << m_name <<  " - \nWell, all you need to do is pour it into a glass and serve";
}
