#include "Die.h"
#include <cstdlib>
#include <ctime> 
#include <iostream> 

using namespace std;

Die::Die() : sides(6){
	roll(); 

}
void Die::roll() {
	faceValue = rand() % sides + 1;

}
int Die::getFaceValue() const {
	return faceValue;

}
int Die::getSides() const {
	return sides;

}