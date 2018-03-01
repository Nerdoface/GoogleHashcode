#include <iostream>
#include <vector>
#include <cmath>  
#include <fstream>
#include "Car.cpp"
#include "FileHandler.cpp"
#include "Route.cpp"

FileHandler file;

void output(std::vector<Car> cars) {
	std::ofstream out("poepiekutaron.txt");
	for (auto& car : cars) {
		std::cout << "output: " << car.routesToTake.size() << std::endl;
		out << car.routesToTake.size();
		for (auto& route : car.routesToTake) {
			out << " " << route.routeIndex;
		}
		out << std::endl;
	}
}

void cleanUp(int step) {
	for (auto it = file.routes.begin(); it != file.routes.end(); )
		if (it->getLength() + step > it->sF)
			file.routes.erase(it++);
		else
			it++;
}

int main(){
	// a_example
	file.openFile("b_should_be_easy.in");
	std::vector<Car> cars(file.nVeh);


	for (int i = 0; i < file.nSteps; ++i) {
		if (file.routes.size() == 0)
			break;
		cleanUp(i);

		std::cout << "step : " << i << " routes: " << file.routes.size() << std::endl;


		for (auto& car : cars) {
			if (car.endStep <= i) {
				car.getFastestRoute(file.routes, i, file.nBon);
			}
		}
	}

	output(cars);
	int aids;
	std::cin >> aids;
	return 0;
}

int getPriority(int step, std::vector<int> route, int bonus, std::vector<std::vector<int>> cars){

	int score = 0;

	int distance = (std::abs(route.at(2) - route.at(0)) + std::abs(route.at(3) - route.at(1)));

	score += distance;

	for (int i = 0; i < cars.size(); i++){
		int cDistance = (std::abs(cars.at(i).at(0) - route.at(0)) + std::abs(cars.at(i).at(1) - route.at(1)));

		if (cDistance == (route.at(4) - step)){
			score += bonus;
		}

	}

	return score;
}