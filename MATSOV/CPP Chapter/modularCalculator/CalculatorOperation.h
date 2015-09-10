#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

#ifndef CALCOP_H
#define CALCOP_H

class CalculatorOperation
{
public:
	// checks whether the operator string matches one of the operator syntaxes
	virtual bool supportsOperation(string op_string) = 0;
	// returns the number of required parameters
	virtual int requiredParameters() = 0;
	// calculates and returns the result
	virtual double calcResult(double currVal, vector<string> params) = 0;
};

#endif
