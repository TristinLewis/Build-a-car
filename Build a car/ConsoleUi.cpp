#include "ConsoleUi.h"
#include "GameLogic.h" 
#include<iomanip> 
#include<iostream> 
#include <vector> 


using namespace std;

ConsoleUi::ConsoleUi() {

}
bool ConsoleUi::askReroll() {
	char answer; 
	do {
		cout << "Would you like to reroll(y/n)" << endl; 
		cin >> answer; 
		answer = tolower(answer); 
	} while (answer != 'y' && answer != 'n');
	return answer == 'y'; 

}
void ConsoleUi::displayRoll(int index) {
	cout << "The current Roll: " << index << endl; 
}
void ConsoleUi::displayDice(const vector<int>diceValues) {
	for (int i = 0; i < 5; i++) {
		cout << "Die: " << i + 1 << " : " << diceValues[i] << endl; 
	}
}
void ConsoleUi::displayRound(int round) {
	cout << endl << "Round:" << round << endl; 
}
void ConsoleUi::displayFinal(const GameLogic& gameLogic) {
	cout << "Final score for you is:  " << gameLogic.getTotal() << endl; 

}
void ConsoleUi::displayScore() {
	
}

int ConsoleUi::chooseScore(const vector<int>& scoresUsed)const {
	int choice;
	while(true){
		cout << "Which would you like to score?(Die between(1-6)) " << endl; 
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
vector<bool> ConsoleUi::getRerollDice() {

	vector<bool> rerollFlags(5, false);

	cout << "Enter dice numbers to reroll separated by spaces (0 to finish): ";
	int input;
	while (true) {
		cin >> input;
		if (input == 0) break;
		if (input >= 1 && input <= 5) {
			rerollFlags[input - 1] = true;
		}
	}
	return rerollFlags;
}

