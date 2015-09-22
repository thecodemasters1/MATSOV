#include <string.h>
#include "Drink.h"

const char* STRING_NOT_FOUND_EXCEPTION = "String not found exception";

Drink::Drink(const char* name)
{
	m_name = new char[100]; // T: 100 magic number, put it in define
	strcpy(m_name, name); // T: can cause buffer overflow, use strncpy, check m_name is not null
}

Drink::~Drink()
{
	delete[] m_name;
}

char* Drink::getName() const
{
	if(m_name == NULL) { throw STRING_NOT_FOUND_EXCEPTION; } // T: use specific exception, no reason it will be null
	return m_name;
}

