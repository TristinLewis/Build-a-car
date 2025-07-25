#include "ConsoleUi.h"
#include "GameLogic.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector> 


using namespace std;

int main() {

    srand(static_cast<unsigned int>(time(nullptr))); //rand seed


    ConsoleUi ui; 
    GameLogic game; 

    const int TOTALROUNDS = 6; 

    for (int round = 1; round <= TOTALROUNDS; round++) {
        game.setRound(round); 
        game.setRoll(1); 

        ui.displayRound(round); 

        game.rollAll(); 
        ui.displayDice(game.getDiceFaceValues()); 

        while (game.getRoll() < 3) {
            if (!ui.askReroll())
                break;
            vector<bool> rerollFlags = ui.getRerollDice();

            game.setRerollDice(rerollFlags);
            game.reroll();

            ui.displayDice(game.getDiceFaceValues());
        }
        int category ,score; 
       category = ui.chooseScore(game.getCategoryStorage());
       
       score = game.calculateScore(game.getDiceFaceValues(), category - 1);

       game.setCategoryScore(category - 1, score); 

       ui.displayScore(); 

       cout << "Current Total: " << game.getTotal() << endl;

    }
    ui.displayFinal(game);
    return 0; 



}