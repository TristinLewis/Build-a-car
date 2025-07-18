#include "ConsoleUi.h"
#include "GameLogic.h" 
#include<iomanip> 
#include<iostream> 


using namespace std;

ConsoleUi::ConsoleUi() {

}
bool ConsoleUi::askReroll() {
	char answer; 
	do {
		cout << "What dice would you like to reroll(y/n)" << endl; 
		cin >> answer; 
		answer = tolower(answer); 
	} while (answer != 'y' && answer != 'n');
}
void ConsoleUi::displayRoll(int index) {
	cout << "The current Roll: " << index << endl; 
}
void ConsoleUi::displayDice(const vector<int>diceValues) {
	for (int i = 0; i < 5; i++) {
		cout << "Die: " << i + 1 << " " << diceValues[i] << endl; 
	}
}
void ConsoleUi::displayRound(int round) {
	cout << endl << "Round:" << round << endl; 
}
void ConsoleUi::displayFinal(const GameLogic& gameLogic) {
	cout << "Annnnnnnnnnd the final score is " << gameLogic.getTotal() << endl; 

}
void ConsoleUi::displayScore() {
	
}

int ConsoleUi::chooseScore(const vector<int>& scoresUsed)const {
	int choice;
	while(true){
		cout << "Which would you like to score? " << endl; 
		cin >> choice; 
		if (choice >= 1 || choice<= 6) {
			if (!scoresUsed[choice - 1]) {
				return choice;
			}
			else {
				cout << " This category is already taken.";
			
			}
		}
	}
}
