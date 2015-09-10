#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Operators.h"

const string UNDEFINED_CHAR = "Undefined char entered.\n";
const string NOT_APPLICABLE_OPERATOR = "Operator does not exist or wrong number of parameters.\n";

const int OPS_COUNT = 7;
CalculatorOperation* ops[OPS_COUNT];

void stringToVec(string input, vector<string>* vec);
double calculateVal(double currVal, vector<string> userInput);
bool isOperator(char c);
void freeOps();

// main function. enter "end" or "End" to close the calculator.
int main()
{
	ops[0] = new OpSet();
	ops[1] = new OpAdd();
	ops[2] = new OpSubstract();
	ops[3] = new OpMultiply();
	ops[4] = new OpDivide();
	ops[5] = new OpSqrt();
	ops[6] = new OpPower();

	double currVal;
	string userInput;
	vector<string> userInputVec;
	bool end = false;
	bool failed = false;
	cout << "Welcome to the modular calculator.\n";

	while(!end)
	{
		cout << "->  ";
		getline(cin, userInput);

		if(userInput.compare("end") == 0 || userInput.compare("End") == 0) {
			end = true;
			cout << "Goods bye!\n\n";
			freeOps();
			return 0;
		}

		try {
			stringToVec(userInput, &userInputVec);
			failed = false;
		} catch(string& exception) {
			cout << exception;
			failed = true;
		}

		if( !failed )
		{
			try {
				currVal = calculateVal(currVal, userInputVec);
			} catch(string& exception) {
				cout << exception;
			}
		}
		cout << "    Current value is: " << currVal << "\n";
	}

	freeOps();
	return 0;
}

// casts the user input's string to a divided "words" in a vector
void stringToVec(string input, vector<string>* vec)
{
	vec->erase(vec->begin(), vec->end());
	int size = input.size();
	int vecIndex = 0;
	string param = "";

	for(int i = 0; i < size; i++)
	{
		if(!isalnum(input.at(i)) && !isOperator(input.at(i)))
		{
			if(input.at(i) == ' ')
			{
				vec->push_back(param);
				param = "";
				++vecIndex;
			} else
			{
				throw UNDEFINED_CHAR;
			}
		} else
		{
			param.push_back(input.at(i));
		}
	}
	vec->push_back(param);
}

// Checks if there is an applicable operator (and parameters number) and returns the new value if there is
// if there is no applicable operator - throws an exception
double calculateVal(double currVal, vector<string> userInput)
{
	for(int i = 0; i < OPS_COUNT; i++)
	{
		if( ops[i]->supportsOperation(userInput.front()) )
		{
			if( userInput.size()-1 != (unsigned int)ops[i]->requiredParameters() )
			{
				throw NOT_APPLICABLE_OPERATOR;
			} else
			{
				vector<string> params;
				for(unsigned int j = 1; j < userInput.size(); j++)
				{
					params.push_back(userInput[j]);
				}
				return ops[i]->calcResult(currVal, params);
			}
		}
	}

	throw NOT_APPLICABLE_OPERATOR;
}

// returns true if c is an non-alphanumeric operator
bool isOperator(char c)
{
	char operators[] = {'+','-','*','/','^'};
	int operators_count = 5;
	for(int i = 0; i < operators_count; i++)
	{
		if(c == operators[i]) {
			return true;
		}
	}
	return false;
}

// frees the operators's array's memory
void freeOps()
{
	for(int i = 0; i < OPS_COUNT; i++)
	{
		delete ops[i];
	}
}
