#include <iostream>
#include <list>
#include <cmath>
#include "Route.cpp"

class Car{


public:

	std::list<Route> routesToTake;

	int posX;
	int posY;

	void getFastestRoute(std::list<Route> routes, int curStep, int bonus){

		
		int shortestDistance = 0;
		std::list<Route>::iterator car;


		std::list<Route>::iterator it;
		for (it = routes.begin(); it != routes.end(); ++it){

			int score = 0;

			int carDistance = (abs(posX - it->sX) + abs(posY - it->sY));

			if (it->sF < carDistance + it->getLength()){
				continue;
			}
			else{
				int numSteps = it->sF - curStep;
				if (carDistance <= numSteps){
					score += it->getLength() + bonus - numSteps;
				}
				else{

					score += it->getLength() - carDistance;

				}
			}

			if (carDistance > shortestDistance){
				shortestDistance = carDistance;
				car = it;
			}
		}

		

		routes.erase(car);

	}


};