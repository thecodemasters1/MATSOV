#include <cstdlib>
#include "Operators.h"
#include "math.h"

#include <iostream>
using namespace std;

bool supports(string op_string, const char** names, int arrLen);

// Set operator possible names
const char* setNames[] = {"Set", "set"};
const int setNamesLen = 2;
// Addition operator possible names
const char* addNames[] = {"+", "add", "Add"};
const int addNamesLen = 3;
// Substraction operator possible names
const char* substractNames[] = {"-", "substract", "Substract", "minus", "Minus"};
const int substractNamesLen = 5;
// Multiplation operator possible names
const char* multiplyNames[] = {"*", "multiply", "Multiply", "times", "Times"};
const int multiplyNamesLen = 5;
// Division operator possible names
const char* divideNames[] = {"/", "divide", "Divide"};
const int divideNamesLen = 3;

// Addition operator methods
bool OpSet::supportsOperation(string op_string)
{
	return supports(op_string, setNames, setNamesLen);
}

double OpSet::calcResult(double currVal, vector<string> params)
{
	return atof(params.front().c_str());
}

// Addition operator methods
bool OpAdd::supportsOperation(string op_string)
{
	return supports(op_string, addNames, addNamesLen);
}

double OpAdd::calcResult(double currVal, vector<string> params)
{
	return (currVal + atof(params.front().c_str()));
}

// Substraction operator methods
bool OpSubstract::supportsOperation(string op_string)
{
	return supports(op_string, substractNames, substractNamesLen);
}

double OpSubstract::calcResult(double currVal, vector<string> params)
{
	return (currVal - atof(params.front().c_str()));
}

// Multiplation operator methods
bool OpMultiply::supportsOperation(string op_string)
{
	return supports(op_string, multiplyNames, multiplyNamesLen);
}

double OpMultiply::calcResult(double currVal, vector<string> params)
{
	return (currVal * atof(params.front().c_str()));
}

// Division operator methods
bool OpDivide::supportsOperation(string op_string)
{
	return supports(op_string, divideNames, divideNamesLen);
}

double OpDivide::calcResult(double currVal, vector<string> params)
{
	return (currVal / atof(params.front().c_str()));
}

const char* sqrtNames[] = {"sqrt", "Sqrt", "Square", "square"};
const int sqrtNamesLen = 4;
const char* powerNames[] = {"^", "pow", "power", "powerof", "Pow", "Power", "Powerof"};
const int powerNamesLen = 7;

bool OpSqrt::supportsOperation(string op_string)
{
	return supports(op_string, sqrtNames, sqrtNamesLen);
}

double OpSqrt::calcResult(double currVal, vector<string> params)
{
	return sqrt(currVal);
}

bool OpPower::supportsOperation(string op_string)
{
	return supports(op_string, powerNames, powerNamesLen);
}

double OpPower::calcResult(double currVal, vector<string> params)
{
	return pow(currVal, atof(params.front().c_str()));
}

// checks whether the operator string matches one of the operator syntaxes
bool supports(string op_string, const char** names, int arrLen)
{
	for(int i = 0; i < arrLen; i++)
	{
		if(op_string.compare(names[i]) == 0)
		{
			return true;
		}
	}
	return false;
}
