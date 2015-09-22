#include "fraction.h"

#include <iostream>
#include <stdexcept>

Fraction::Fraction(int nominator, int denominator)
{
	if(denominator == 0) {
		throw std::overflow_error("Divide by Zero Exception");
	}
	m_nominator = nominator;
	m_denominator = denominator;
}

Fraction::Fraction(int number)
{
	m_nominator = number;
	m_denominator = 1;
}

void Fraction::setDenominator(int newDenom)
{
	if(newDenom == 0) {
		throw std::overflow_error("Divide by Zero Exception");
	}
	m_denominator = newDenom;
}

void Fraction::reduction()
{
	int maxDivider = 1;

	for(int testDivider = 2; testDivider <= (m_nominator > m_denominator ? m_denominator : m_nominator); testDivider++)
	{
		if(m_nominator % testDivider == 0 && m_denominator % testDivider == 0)
		{
			maxDivider = testDivider;
		}
	}

	m_nominator = m_nominator / maxDivider;
	m_denominator = m_denominator / maxDivider;
}

Fraction Fraction::operator +(const Fraction& frac) const
{
	int newNominator;
	int newDenominator;

	if(m_denominator != frac.getDenominator())
	{
		newNominator = frac.getDenominator()*m_nominator + frac.getNominator()*m_denominator;
		newDenominator = frac.getDenominator()*m_denominator;
	} else
	{
		newNominator = m_nominator + frac.getNominator();
		newDenominator = m_denominator;
	}

	Fraction newFrac = Fraction(newNominator, newDenominator);
	newFrac.reduction();
	return newFrac;
}

Fraction Fraction::operator -(const Fraction& frac) const // nominators substraction after denominators equalization
{
	int newNominator;
	int newDenominator;

	if(m_denominator != frac.getDenominator())
	{
		newNominator = frac.getDenominator()*m_nominator - frac.getNominator()*m_denominator;
		newDenominator = frac.getDenominator()*m_denominator;
	} else
	{
		newNominator = m_nominator - frac.getNominator();
		newDenominator = m_denominator;
	}

	Fraction newFrac = Fraction(newNominator, newDenominator);
	newFrac.reduction();
	return newFrac;
}

Fraction Fraction::operator *(const Fraction& frac) const // Multiple nominators and denominators
{
	Fraction newFrac = Fraction( m_nominator*frac.getNominator(),
					 	 	 	 	 m_denominator*frac.getDenominator() );
	newFrac.reduction();
	return newFrac;
}

Fraction Fraction::operator /(const Fraction& frac) const // Multiple nominator with denominator
{
	if(frac.getNominator() == 0) { throw std::overflow_error("Divide by Zero Exception"); }
	Fraction newFrac =  Fraction( m_nominator*frac.getDenominator(),
								  m_denominator*frac.getNominator() );
	newFrac.reduction();
	return newFrac;
}

Fraction& Fraction::operator +=(const Fraction& frac)
{
	Fraction newFrac = operator +(frac);
	m_nominator = newFrac.getNominator();
	m_denominator = newFrac.getDenominator();
	return *this;
}

Fraction& Fraction::operator -=(const Fraction& frac)
{
	Fraction newFrac = operator -(frac);
	m_nominator = newFrac.getNominator();
	m_denominator = newFrac.getDenominator();
	return *this;
}

Fraction& Fraction::operator *=(const Fraction& frac)
{
	Fraction newFrac = operator *(frac);
	m_nominator = newFrac.getNominator();
	m_denominator = newFrac.getDenominator();
	return *this;
}

Fraction& Fraction::operator /=(const Fraction& frac)
{
	Fraction newFrac = operator /(frac);
	m_nominator = newFrac.getNominator();
	m_denominator = newFrac.getDenominator();
	return *this;
}

Fraction& Fraction::operator ++()
{
	Fraction newFrac = operator +(Fraction(1));
	m_nominator = newFrac.getNominator();
	m_denominator = newFrac.getDenominator();
	return *this;
}

Fraction& Fraction::operator --()
{
	Fraction newFrac = operator -(Fraction(1));
	m_nominator = newFrac.getNominator();
	m_denominator = newFrac.getDenominator();
	return *this;
}

bool Fraction::operator ==(const Fraction& frac) const
{
	float num1 = float();
	float num2 = float(frac);

	return (num1 == num2);
}

bool Fraction::operator !=(const Fraction& frac) const
{
	return !(operator ==(frac));
}

bool Fraction::operator >(const Fraction& frac) const
{
	Fraction newFrac = operator-(frac);
	return (float(newFrac) > 0);
}

bool Fraction::operator <(const Fraction& frac) const
{
	return !(operator >(frac));
}

bool Fraction::operator >=(const Fraction& frac) const
{
	return (operator>(frac) || operator==(frac));
}

bool Fraction::operator <=(const Fraction& frac) const
{
	return (operator<(frac) || operator==(frac));
}
