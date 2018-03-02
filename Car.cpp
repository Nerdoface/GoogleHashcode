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
		
		double maxScore = -1000000;
		std::list<Route>::iterator car;


		std::list<Route>::iterator it;


		for (it = routes.begin(); it != routes.end(); ++it){

			double score = 0;
			int tendStep = 0;

			int carDistance = (abs(posX - it->sX) + abs(posY - it->sY));

			if (it->sF < carDistance + it->getLength() + curStep){
				continue;
			}
			
			int stepToStart = it->sS - curStep;
			if (carDistance <= stepToStart){
				score += (double)(it->getLength() + bonus) / (it->getLength() + stepToStart);
				tendStep = it->getLength() + stepToStart + curStep;
			}
			else{
				score +=  (double)(it->getLength()) / (it->getLength() + carDistance);
				tendStep = it->getLength() + carDistance + curStep;
			}


			if (score > maxScore){
				maxScore = score;
				car = it;
				endStep = tendStep;
				tempPosX = it->eX;
				tempPosY = it->eY;
			}
		}

		posX = tempPosX;
		posY = tempPosY;
		

		routesToTake.push_back(*car);
		routes.erase(car);


	}


};
