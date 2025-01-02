#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <random>

std::vector<std::vector<int>> gameMap {
	        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	    };


	class blockRan{
				public:

					std::vector<std::vector<int> > block = {
							{0,0,0},
							{0,0,0},
							{0,0,0}
					};
					std::string randMCard;
					void blockChange(int Er,int Ec){
						std::mt19937 gen(1234);
						std::uniform_int_distribution<int> dist(0,2);

						int cardRand= dist(gen);
						if (cardRand == 1){
							randMCard = "row";
						}
						else{
							randMCard = "col";
						}
						if (randMCard == "row"){
							int i = dist(gen);
							block[i][0]=1;
							block[i][1]=1;
							block[i][2]=1;

						}
						else {
							int j = dist(gen);;
							block[0][j]=1;
							block[1][j]=1;
							block[2][j]=1;
						}


						gameMap[Er-1][Ec-1] = block[0][0];
						gameMap[Er-1][Ec] = block[0][1];
						gameMap[Er-1][Ec+1] = block[0][2];

						gameMap[Er][Ec-1] = block[1][0];
						gameMap[Er][Ec] = block[1][1];
						gameMap[Er][Ec+1] = block[1][2];

						gameMap[Er+1][Ec-1] = block[2][0];
						gameMap[Er+1][Ec] = block[2][1];
						gameMap[Er+1][Ec+1] = block[2][2];
			};



};

	void printGameMap(const std::vector<std::vector<int>>& gameMap) {
	    for (const auto& row : gameMap) {
	        for (const auto& element : row) {
	            std::cout << element << " "; // Print each element in the row, separated by space
	        }
	        std::cout << std::endl; // Move to the next line after each row
	    }
	}


int main(){
	blockRan A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P;
		A.blockChange(2,2);
		B.blockChange(2,5);
		C.blockChange(2,8);
		D.blockChange(2,11);
		E.blockChange(5,5);
		F.blockChange(5,11);
		G.blockChange(5,2);
		H.blockChange(5,5);
		I.blockChange(8,11);
		J.blockChange(8,2);
		K.blockChange(8,5);
		L.blockChange(8,11);
		M.blockChange(11,11);
		N.blockChange(11,2);
		O.blockChange(11,5);
		P.blockChange(11,11);
	printGameMap(gameMap);

return 0;
}







