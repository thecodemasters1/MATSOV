#ifndef DRINK_H
#define DRINK_H

class Drink
{
public:
	Drink(const char* name);
	virtual ~Drink();
	virtual char* getName() const;
	virtual void prepare() const = 0; // T: better prepare return a string and not print to std

protected:
	char* m_name;
};

#endif
