#include <iostream> // T: missing ifdef header

class Fraction
{
public:
	Fraction(int nominator, int denominator); // basic constructor
	Fraction(int number); // constructor from int

	void setNominator(int newNom) { m_nominator = newNom; }
	void setDenominator(int newDenom) { m_denominator = newDenom; } // T: setting zero should cause exception
	int getNominator() const { return m_nominator; }
	int getDenominator() const { return m_denominator; }

	void reduction();
	operator float() const { return (float(m_nominator) / float(m_denominator)); } // T: check denominator not zero

	Fraction operator -() { return Fraction(-m_nominator, m_denominator); } // T: function should be const
	Fraction operator +(const Fraction& frac) const;
	Fraction operator -(const Fraction& frac) const;
	Fraction operator *(const Fraction& frac) const;
	Fraction operator /(const Fraction& frac) const;
	Fraction& operator +=(const Fraction& frac);
	Fraction& operator -=(const Fraction& frac);
	Fraction& operator *=(const Fraction& frac);
	Fraction& operator /=(const Fraction& frac);
	Fraction& operator ++();
	Fraction& operator --();
	bool operator ==(const Fraction& frac) const;
	bool operator !=(const Fraction& frac) const;
	bool operator >(const Fraction& frac) const;
	bool operator <(const Fraction& frac) const;
	bool operator >=(const Fraction& frac) const;
	bool operator <=(const Fraction& frac) const;

	friend std::ostream& operator <<(std::ostream& os, const Fraction& frac) // T: nice
	{
		if(frac.getNominator() == 0) {
			os << "0";
		} else if(frac.getDenominator() == 1) {
			os << frac.getNominator();
		} else {
			os << frac.getNominator() << '/' << frac.getDenominator();
		}
		return os;
	}

private:
	int m_nominator;
	int m_denominator;
};
