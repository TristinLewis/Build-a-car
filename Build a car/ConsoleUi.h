#ifndef ConsoleUi_h 
#define ConsoleUi_h 
#include "GameLogic.h"
#include <iostream> 
#include <vector> 

class ConsoleUi {
private:

	vector<string> categoryStorage;
	GameLogic gamelogic; 

	
public:
	ConsoleUi();
	bool askReroll();
	void displayRoll(int index);
	void displayDice(const vector<int>diceValues);
	void displayRound(int round);
	void displayFinal(const GameLogic& gameLogic);
	void displayScore();
	
	int chooseScore(const vector<int>& scoresUsed)const; 

};


#endif
