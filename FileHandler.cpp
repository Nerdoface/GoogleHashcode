#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include "Route.cpp"

class FileHandler{

private:



//	std::vector<std::vector<int>> routes;



public:

	int nRows;
	int nCols;

	int nVeh;
	int nRides;

	int nBon;
	int nSteps;

	std::list<Route> routes;


	int index = 0;

	void openFile(std::string location){
		std::ifstream bestand(location);
		std::string line;

		bool eersteRegel = true;

		int rNummer = 0;

		if (bestand.is_open()){
			while (std::getline(bestand, line))
			{
				if (eersteRegel){

					int aantalSpaces = 0;
					std::string temp;

					for (std::string::size_type i = 0; i < line.size(); ++i) {
						

						if (line[i] == ' '){

							std::string::size_type sz;
							int t = std::stoi(temp, &sz);

							switch (aantalSpaces){
								case 0:

									nRows = t;
									temp.clear();
									break;
								case 1:

									nCols = t;
									temp.clear();
									break;
								case 2:

									nVeh = t;
									temp.clear();
									break;
								case 3:

									nRides = t;
									temp.clear();
									break;
								case 4:

									nBon = t;
									temp.clear();
									break;
								case 5:

									nSteps = t;
									temp.clear();
									break;
								

							}
							
						}
						else{
							temp += line[i];
						}
						

					}


					eersteRegel = false;
				}
				else{

					std::string temp;
					Route r;


					int aantalSpaces = 0;

					for (std::string::size_type i = 0; i < line.size(); ++i) {


						if (line[i] == ' '){

							std::string::size_type sz;
							int t = std::stoi(temp, &sz);

							if (aantalSpaces == 0){
								r.sX = t;
							}
							if (aantalSpaces == 1){
								r.sY = t;
							}
							if (aantalSpaces == 2){
								r.eX = t;
							}
							if (aantalSpaces == 3){
								r.eY = t;
							}
							if (aantalSpaces == 4){
								r.sS = t;
							}
							if (aantalSpaces == 5){
								r.sF = t;
							}

							aantalSpaces++;

							}
						else{

							temp += line[i];
						}

						
		
					}

					r.routeIndex = index;

					index++;
					routes.push_back(r);
				}

				std::cout << line << '\n';
				rNummer++;
			}
			bestand.close();
		}
	}


};