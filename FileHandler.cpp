#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class FileHandler{

private:

	int nRows;
	int nCols;

	int nVeh;
	int nRides;

	int nBon;
	int nSteps;

	std::vector<std::vector<int>> routes;

public:




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
					std::vector<int> vVec;


					for (std::string::size_type i = 0; i < line.size(); ++i) {


						if (line[i] == ' '){

							std::string::size_type sz;
							int t = std::stoi(temp, &sz);

							vVec.push_back(t);
							temp.clear();

							}
						else{

							temp += line[i];
						}

						
		
					}

					routes.push_back(vVec);
				}

				std::cout << line << '\n';
				rNummer++;
			}
			bestand.close();
		}
	}


};