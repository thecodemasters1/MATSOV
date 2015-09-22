#include "CalculatorOperation.h" // T: missing ifdef header

/* Non-mathematical operators */

// Set operator definition
class OpSet : public CalculatorOperation
{
public:
	bool supportsOperation(string op_string);
	int requiredParameters() { return 1; }
	double calcResult(double currVal, vector<string> params);
};

/* Mathematical operators */

// Addition operator definition
class OpAdd : public CalculatorOperation
{
public:
	bool supportsOperation(string op_string);
	int requiredParameters() { return 1; }
	double calcResult(double currVal, vector<string> params);
};

// Substraction operator definition
class OpSubstract : public CalculatorOperation
{
public:
	bool supportsOperation(string op_string);
	int requiredParameters() { return 1; }
	double calcResult(double currVal, vector<string> params);
};

// Multiplation operator definition
class OpMultiply : public CalculatorOperation
{
public:
	bool supportsOperation(string op_string);
	int requiredParameters() { return 1; }
	double calcResult(double currVal, vector<string> params);
};

// Division operator definition
class OpDivide : public CalculatorOperation
{
public:
	bool supportsOperation(string op_string);
	int requiredParameters() { return 1; }
	double calcResult(double currVal, vector<string> params);
};

// Exponent operators

class OpSqrt : public CalculatorOperation
{
public:
	bool supportsOperation(string op_string);
	int requiredParameters() { return 0; }
	double calcResult(double currVal, vector<string> params);
};

class OpPower : public CalculatorOperation
{
public:
	bool supportsOperation(string op_string);
	int requiredParameters() { return 1; }
	double calcResult(double currVal, vector<string> params);
};
