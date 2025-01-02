#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <random>

std::vector<std::vector<int>> gameMap= {
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

class blockRan {
public:
    std::vector<std::vector<int>> block = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    std::string randMCard;

    // Randomized block change
    void blockChange(int Er, int Ec, std::mt19937& gen) {
        std::uniform_int_distribution<> dist(0, 1);  // Random 0 or 1
        int cardRand = dist(gen); // Generate 0 or 1 for row or column choice

        if (cardRand == 1) {
            randMCard = "row";
        } else {
            randMCard = "col";
        }

        if (randMCard == "row") {
            std::uniform_int_distribution<> rowDist(0, 2);
            int i = rowDist(gen); // Random row selection (0-2)
            block[i][0] = 1;
            block[i][1] = 1;
            block[i][2] = 1;
        } else {
            std::uniform_int_distribution<> colDist(0, 2);
            int j = colDist(gen); // Random column selection (0-2)
            block[0][j] = 1;
            block[1][j] = 1;
            block[2][j] = 1;
        }

        // Update the game map with the new block placement
        gameMap[Er-1][Ec-1] = block[0][0];
        gameMap[Er-1][Ec] = block[0][1];
        gameMap[Er-1][Ec+1] = block[0][2];

        gameMap[Er][Ec-1] = block[1][0];
        gameMap[Er][Ec] = block[1][1];
        gameMap[Er][Ec+1] = block[1][2];

        gameMap[Er+1][Ec-1] = block[2][0];
        gameMap[Er+1][Ec] = block[2][1];
        gameMap[Er+1][Ec+1] = block[2][2];
    }
};

// Function to print the game map
void printGameMap(const std::vector<std::vector<int>>& gameMap) {
    for (const auto& row : gameMap) {
        for (const auto& element : row) {
            std::cout << element << " "; // Print each element in the row, separated by space
        }
        std::cout << std::endl; // Move to the next line after each row
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());  // Random number generator, seeded once

    // Create blockRan objects
    blockRan A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P;

    // Make random changes to the blocks at specified locations
    A.blockChange(2, 2, gen);
    B.blockChange(2, 5, gen);
    C.blockChange(2, 8, gen);
    D.blockChange(2, 11, gen);
    E.blockChange(5, 5, gen);
    F.blockChange(5, 11, gen);
    G.blockChange(5, 2, gen);
    H.blockChange(5, 5, gen);
    I.blockChange(8, 11, gen);
    J.blockChange(8, 2, gen);
    K.blockChange(8, 5, gen);
    L.blockChange(8, 11, gen);
    M.blockChange(11, 11, gen);
    N.blockChange(11, 2, gen);
    O.blockChange(11, 5, gen);
    P.blockChange(11, 11, gen);

    // Print the game map
    printGameMap(gameMap);

    return 0;
}
