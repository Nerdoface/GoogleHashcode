#include <cmath>





class Route{

public:
	int sX;
	int sY;

	int eX;
	int eY;

	int sS;
	int sF;


	int getLength(){

		return (abs(eX - sX) + abs(eY - sY));

	}

};