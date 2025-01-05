#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <random>

class blockRan {
    public:
    std::vector<std::vector<int>> block = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    std::string randMCard;

    // Randomized block change
    void blockChange(int Er, int Ec, std::mt19937& gen, std::vector<std::vector<int>> & V) {
        std::uniform_int_distribution<> dist(0, 1);  // Random 0 or 1
        int cardRand = dist(gen); // Generate 0 or 1 for row or column choice
        if (Er - 1 >= 0 && Er + 1 < V.size() && Ec - 1 >= 0 && Ec + 1 < V[0].size()) {

        if (cardRand == 1) {
            randMCard = "row";
        } else {
            randMCard = "col";
        }

        if (randMCard == "row") {
            std::uniform_int_distribution<> rowDist(0, 2);
            std::uniform_int_distribution<> holeDist(0, 2);
            int i = rowDist(gen); // Random row selection (0-2)
            block[i][0] = 1;
            block[i][1] = 1;
            block[i][2] = 1;
            int k = holeDist(gen);
            block[i][k]=0;
            
        } else {
            std::uniform_int_distribution<> colDist(0, 2);
            int j = colDist(gen); // Random column selection (0-2)
            block[0][j] = 1;
            block[1][j] = 1;
            block[2][j] = 1;
            int l = colDist(gen);
            block[l][j]=0;
            
        }
        V[Er-1][Ec-1] = block[0][0];
        V[Er-1][Ec] = block[0][1];
        V[Er-1][Ec+1] = block[0][2];

        V[Er][Ec-1] = block[1][0];
        V[Er][Ec] = block[1][1];
        V[Er][Ec+1] = block[1][2];

        V[Er+1][Ec-1] = block[2][0];
        V[Er+1][Ec] = block[2][1];
        V[Er+1][Ec+1] = block[2][2];
        }

    }

};

class mapGen {
    public:
    int ranNum(){
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<int> dist(3,20);
        int randNum = dist(gen);
        while (randNum != 5 && randNum != 8 && randNum != 11 && randNum != 14 && randNum != 17 && randNum != 20){
            randNum = dist(gen);
        }
        int mapSize = randNum;
        std::cout << randNum<< "\n";
        return mapSize;
    }

    class mapBase{
        public:
            std::vector<std::vector<int>> original;
            void mapSizeAdd(int a) {
                for (int i=0; i<a; i++){
                    std::vector<int> row;
                    for (int j=0; j<a; j++){
                        
                        if (j > 0 && j < a-1 && i > 0 && i < a-1){
                            row.push_back(0);
                        }
                        else{
                            row.push_back(1);
                        }

                        std::cout << row[j] << " ";
                        if (j == a-1){
                            std::cout << std::endl;
                        }
                    }
                    original.push_back(row);
                }
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<int> dist(3,20);
                int val = dist(gen);
                blockRan hah;
                for (int i = 0; i < a; i++){
                    for (int j = 0; j<a; j++){
                        if (i==2 || i==5 || i==8){
                            switch(j){
                                case(2):
                                    hah.blockChange(i,j,gen,original);
                                    break;
                                case(5):
                                    hah.blockChange(i,j,gen,original);
                                    break;
                                case(8):
                                    hah.blockChange(i,j,gen,original);
                                    break;
                            }
                        }
                        
                        
                    }
                }
            
        }
        void displayMap(int a){
            for (int i=0; i<a; i++){
                std::vector<int> row;
                for (int j=0; j<a; j++){                            
                    if (j > 0 && j < a-1 && i > 0 && i < a-1){
                        row.push_back(0);
                    }
                    else{
                        row.push_back(1);
                    }
                    std::cout << row[j] << " ";
                    if (j == a-1){
                        std::cout << std::endl;
                    }
                }
            }
        }

    };

    void step1() {
        
        mapBase hi;
        int d = ranNum();
        hi.mapSizeAdd(d);
        hi.displayMap(d);
    }
    //void testBlock(int c){
    //    std::random_device rd;
    //    std::mt19937 gen(rd());
    //    std::uniform_int_distribution<int> dist(3,20);
    //    int val = dist(gen);
    //    blockRan hah;
    //    for (int i = 0; i < c; i++){
    //        for (int j = 0; j<c; j++){
    //            if (i+1 % 3 == 0 || j+1 % 3 == 0){
    //                hah.blockChange(i,j,gen);
    //            }
    //        }
    //    }
    //}


};
class mapFun{
    public:
        int testBlock;


};


int main() {
    
    mapGen a;
    a.step1();
    

    return 0;

}
