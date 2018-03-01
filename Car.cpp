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
		if (routes.size() == 0) {
			endStep = 10000000;
			return;
		}
		std::cout << "getFastestRoute. step: " << curStep << " routes: " << routes.size() << std::endl;
		
		int maxScore = -1000000;
		std::list<Route>::iterator car;


		std::list<Route>::iterator it;


		for (it = routes.begin(); it != routes.end(); ++it){

			int score = 0;
			int tendStep = 0;

			int carDistance = (abs(posX - it->sX) + abs(posY - it->sY));

			if (it->sF < carDistance + it->getLength() + curStep){
				continue;
			}
			else{
				int numSteps = it->sF - curStep;
				int stepToStart = it->sS - curStep;
				if (carDistance >= stepToStart - bonus){
					score += -it->getLength() + bonus - stepToStart;
					tendStep = it->getLength() + stepToStart + curStep;
				}
				else{

					score += -it->getLength() - carDistance;
					tendStep = it->getLength() + carDistance + curStep;

				}
			}

			if (score > maxScore){
				maxScore = score;
				car = it;
				endStep = tendStep;
			}
		}

		

		routesToTake.push_back(*car);
		routes.erase(car);


	}


};