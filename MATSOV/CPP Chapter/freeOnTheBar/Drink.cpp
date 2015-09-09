#include <string.h>
#include "Drink.h"

const char* STRING_NOT_FOUND_EXCEPTION = "String not found exception";

Drink::Drink(const char* name)
{
	m_name = new char[100];
	strcpy(m_name, name);
}

Drink::~Drink()
{
	delete[] m_name;
}

char* Drink::getName() const
{
	if(m_name == NULL) { throw STRING_NOT_FOUND_EXCEPTION; }
	return m_name;
}

