#include <iostream>
#include <list>
#include <cmath>
#include "Route.cpp"

class Car{


public:

	std::list<Route> routesToTake;

	int posX;
	int posY;

	int endStep;

	void getFastestRoute(std::list<Route>& routes, int curStep, int bonus){
		std::cout << curStep << std::endl;
		
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
					endStep = it->getLength() + numSteps;
				}
				else{

					score += it->getLength() - carDistance;
					endStep = it->getLength() + carDistance;

				}
			}

			if (carDistance > shortestDistance){
				shortestDistance = carDistance;
				car = it;
			}
		}

		

		routesToTake.push_back(*car);
		routes.erase(car);


	}


};