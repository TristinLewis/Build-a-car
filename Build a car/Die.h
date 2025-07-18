#ifndef DIE_H
#define DIE_H

class Die {
private:
	const int sides;
	int faceValue;

public:

	Die();

	void roll();
	int getFaceValue() const;
	int getSides() const;

};
#endif 


