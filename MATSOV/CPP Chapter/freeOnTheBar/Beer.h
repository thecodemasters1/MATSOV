#include <iostream>
#include "Drink.h"
using namespace std;

class Beer: public Drink
{
public:
	Beer(const char* name);
	void prepare() const;
};
