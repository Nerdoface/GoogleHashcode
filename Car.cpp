#include <iostream>
#include <list>
#include <cmath>
#include "Route.cpp"

class Car{


public:

	std::list<Route> routesToTake;

	int posX;
	int posY;


	void getFastestRoute(std::list<Route> routes){

		
		int shortestDistance = -1;
		std::list<Route>::iterator car;


		std::list<Route>::iterator it;
		for (it = routes.begin(); it != routes.end(); ++it){
			int carDistance = it->getLength() - (abs(posX - it->eX) + abs(posY - it->eY));

			if (shortestDistance == -1 || carDistance < shortestDistance){
				shortestDistance = carDistance;
				car = it;
			}
		}

		

		routes.erase(car);

	}


};