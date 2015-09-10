#include <iostream>
#include <stdlib.h>
using namespace std;

// Beer
#include "Beer.h"
// Red Wines
#include "RedWines.h"
// White Wines
#include "WhiteWines.h"

const int SHELF_SIZE = 10;

void printOptions(Drink* stock[]);
void freeStock(Drink* stock[]);

int main()
{
	Drink* stock[SHELF_SIZE];
	// Beers
	stock[0] = new Beer("Heineken");
	stock[1] = new Beer("Carlsberg");
	stock[2] = new Beer("Maccabi");
	stock[3] = new Beer("Tuburg");
	// White Wines
	stock[4] = new CarmelRiesling(1989);
	stock[5] = new GolanSmadar(1991);
	stock[6] = new YardenChardonnay(1997);
	// Red Wines
	stock[7] = new Chianti(2007);
	stock[8] = new YardenHermon(2003);
	stock[9] = new YardenCabarnetSauvignon(1999);
	stock[10] = new ChadeauMargot(2010);

	bool barClosed = false;
	int userChoice = 200;
	char* userInput = new char[3];
	Drink* lastDrink = NULL;

	while(!barClosed)
	{
		do
		{
			cout << "What can I get you, sir? (0 - list options)\n\n";
			cin >> userInput;
			userChoice = atoi(userInput);
			cout << "\n";
		} while(userChoice != 0 && userChoice != 99 && userChoice != 100 && userChoice < 1 && userChoice > SHELF_SIZE);
		switch(userChoice)
		{
		case 0:
			printOptions(stock);
			break;
		case 99:
			if(lastDrink == NULL)
			{
				cout << "You didn't order anything yet!\n\n";
			}
			else {
				lastDrink->prepare();
				cout << "\n\n";
			}
			break;
		case 100:
			cout << "Bar is closed. Good Night!\n\n";
			barClosed = true;
			freeStock(stock);
			return 0;
			break;
		default: lastDrink = stock[userChoice-1];
				cout << "One " << lastDrink->getName() << " coming up, sir.\n\n";
		}
	}
}

void printOptions(Drink* stock[])
{
	cout << "(0)   list options\n";
	for(int i = 0; i < SHELF_SIZE; i++)
	{
		cout << "(" << i+1 << ")   " << stock[i]->getName() << "\n";
	}
	cout << "(99)  How did you prepare my last drink?\n";
	cout << "(100) Leave the bar\n\n";
}

void freeStock(Drink* stock[])
{
	delete[] stock;
}
