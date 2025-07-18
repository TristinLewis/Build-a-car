#include "GameLogic.h"
#include "ConsoleUi.h"
#include <iostream> 
#include <string> 


using namespace std; 


GameLogic::GameLogic() : roll(0), round(0), total(0), categoryScores(6,0), categoryUsed(6,false),
dice(5), rerollDice(5,false){
	for (int i = 0; i < 5; i++) {
		dice[i].roll(); 
	}
}

// setters
void GameLogic::setRoll(int r) {
	roll = r; 
}
void GameLogic::setRound(int roun) {
	round = roun;
}
void GameLogic::setTotal() {
	score = 0; 
	for (int i = 0; i < 6; i++){
		score+= categoryScores[i];
	}
}
void GameLogic::setRerollDice(const vector<bool>& rerollDiceInput) {
	rerollDice = rerollDiceInput; 
}
void GameLogic::setCategoryScore(int index, int score) {
	categoryScores[index] = score;
	categoryUsed[index] = true; 
	setTotal(); 

}


// getters
int GameLogic::getRoll() const {
	return roll; 
}
int GameLogic::getRound() const {
	return round; 
}
int GameLogic::getTotal() const {
	return score; 
}
int GameLogic::getCategoryScore(int index) const {
	return categoryScores[index]; 
}

vector<int> GameLogic::getCategoryStorage()const {
	return categoryScores; 
}
vector<int> GameLogic::getDiceFaceValues() const {
	vector<int> values; 
	for (int i = 0; i < 5; i++) {
		values.push_back(dice[i].getFaceValue()); 

	}
	return values; 
}


// misc
void GameLogic::rollAll() {
	for (int i = 0; i < dice.size(); i++) {
		dice[i].roll(); 

	}
}
void GameLogic::reroll() {
	for (int i = 0; i < 5; i++) {
		if (rerollDice[i]) {
			dice[i].roll(); 

		}
	}
	if (roll < 3) {
		roll++; 

	}
}
void GameLogic::updateScore() {
	setTotal(); 
}


bool GameLogic::allCategoriesUsed()  {
	for (int i = 0; i < 6; i++) {
		if (!categoryUsed[i]) {
			return false;
		}
	}
	return true; 
}

