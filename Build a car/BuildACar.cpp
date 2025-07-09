#include <iostream> 
#include <string> 

using namespace std;


class Car {

private: 
	string color;
	double price; 
	long km; 
	string model; 
	bool isRunning; 
	int position = 0; 

public: 
	//Setters
	void setColor(string c); 
	void setPrice(double p); 
	void setKm(long k); 
	void setModel(string m);
	//Getters
	string getColor()const;
	double getPrice()const;
	long getKm()const;
	string getModel()const;
	//Misc Functions 
	void start(); 
	void stop(); 
	void forward(int distance); 
	void backwards(int distance);
	string describeCar(); 
};


int main() {

	Car myCar; 

	cout << myCar.describeCar(); 
	myCar.setColor("Grey"); 
	myCar.setModel("Rogue"); 
	myCar.setKm(20000000);  
	myCar.setPrice(10000); 


	return 0; 
}
void Car::setColor(string c) {
	color = c; 
};
void Car::setPrice(double p) {
	price = p; 
};
void Car::setKm(long k) {
	km = k; 
};
void Car::setModel(string m) {
	model = m; 
};
string Car::getColor()const {
	return color; 
};
double Car::getPrice()const {
	return price; 
};
long Car::getKm()const {
	return km;
};
string Car::getModel()const {
	return model; 
};
void Car::start() {
	isRunning = true; 
};
void Car::stop() {
	isRunning = false; 
};
void Car::forward(int distance) {
	position += distance; 
};
void Car::backwards(int distance) {
	position - +distance; 
};
string Car::describeCar() {
	return "A " + color + " " + model + " that is worth $" + to_string(price) + " width " +
		to_string(km) + " kilometers. "; 
}