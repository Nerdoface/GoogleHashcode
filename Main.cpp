#include <iostream>
#include <vector>
#include <cmath>  


int main(){


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