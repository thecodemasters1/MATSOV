#ifndef DRINK_H
#define DRINK_H

class Drink
{
public:
	Drink(const char* name);
	virtual ~Drink();
	virtual char* getName() const;
	virtual void prepare() const = 0;

protected:
	char* m_name;
};

#endif
