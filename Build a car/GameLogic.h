#ifndef GameLogic_h
#define GameLogic_h
#include "Die.h"
#include <iostream> 
#include <vector> 
using namespace std; 

class GameLogic {
private:
    int roll, round, score;
    vector<Die> dice;
    vector<int> categoryScores;
    vector<int>categoryUsed;
    vector<bool> rerollDice; 

public:
    GameLogic();

    // setters
    void setRoll(int r);
    void setRound(int roun);
    void setTotal();
    void setRerollDice(const vector<bool>& rerollDiceInput);
    void setCategoryScore(int index, int score);


    // getters
    int getRoll() const;
    int getRound() const;
    int getTotal() const;
    int getCategoryScore(int index) const;

    vector<int> getCategoryStorage()const;
    vector<int> getDiceFaceValues() const;
 

    // misc
    void rollAll();
    void reroll();
    void updateScore(); 


    bool allCategoriesUsed(); 


};
#endif