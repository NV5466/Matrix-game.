#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <SDL2/SDL.h>



// Number generation class
class numberGen {
    public:
        numberGen() : engine(std::random_device{}()) {}

        unsigned int GRInt(int min, int max) {
            std::uniform_int_distribution<int> dist(min, max);
            return dist(engine);
        }

        int SizeCorr(int m, int min, int max) {
            if (min > max || min < 0 || m <= 0) {
                throw std::invalid_argument("Invalid arguments for SizeCorr.");
            }
            for (int i = 0; i < 1000; ++i) {
                int size = GRInt(min, max);
                if (size % m == 0) {
                    return size;
                }
            }
            throw std::runtime_error("Failed to generate a valid size.");
        }


    private:
        std::mt19937 engine; // Persistent random engine
    };


//Map generation class
class roomGen{
    public:
    //This class is for accessing members used for randomizing parts of a map room.
    class blockRand2{
        public:
        numberGen g;



        std::vector<std::vector<int>> blockRandiC2(){
            std::vector<std::vector<int>> block = {
                {0,0,0},
                {0,0,0},
                {0,0,0}
            };
            bool isCol = g.GRInt(0,1);
            unsigned int columnNum;
            unsigned int rowNum;
            if (isCol == 1){
                columnNum = g.GRInt(0,2);
                for ( unsigned int i=0; i<=2; i++){
                        block[i][columnNum]=1;
                    }
                    int rNum=g.GRInt(0,2);
                    block[rNum][columnNum]=0;
            }
            
            else{
                rowNum=g.GRInt(0,2);
                for (unsigned int i=0; i<=2; i++){
                        block[rowNum][i]=1;
                }
                int cNum=g.GRInt(0,2);
                block[rowNum][cNum]=0;


            }
            return block;
        }


            //Displaying the block. Just for testing.
            // for(int i =0; i<=2; i++){
            //    for(int j = 0; j<=2; j++){
            //        std::cout << block[i][j] << " ";
            //    }
            //    std::cout << std::endl;
            //}
            //Debug for block func


            // var y is the 2D vector to change
        void workingCombo(std::vector<std::vector<int>>& y, int size) {
            int grid = size / 3;
            for (int row = 0; row < grid; ++row) {
                for (int col = 0; col < grid; ++col) {
                    change(y, blockRandiC2(), row * 3 + 2, col * 3 + 2);
                }
            }
        }


        
        void change(std::vector<std::vector<int>>& x,std::vector<std::vector<int>> blk, unsigned int row, unsigned int col){
            if (row < 1 || row >= x.size() - 1 || col < 1 || col >= x[0].size() - 1) {
                std::cerr << "Invalid indices for change function." << std::endl;
                return;
            }
            
            x[row-1][col-1] = blk[0][0];
            
            x[row-1][col] = blk[0][1];
            x[row-1][col+1] = blk[0][2];

            x[row][col-1] = blk[1][0];
            x[row][col] = blk[1][1];
            x[row][col+1] = blk[1][2];

            x[row+1][col-1] = blk[2][0];
            x[row+1][col] = blk[2][1];
            x[row+1][col+1] = blk[2][2];
        }

    };




    //Code that is all bunched together with ducttape and sticks.
    /*void blockRan2(){
        std::vector<std::vector<int>> block = {
                {0,0,0},
                {0,0,0},
                {0,0,0}
        };

        bool isCol = GRInt(0,1);
        int columnNum;
        int rowNum;
        if (isCol == 1){
            columnNum = GRInt(0,2);
            for (int i=0; i<=2; i++){
                    block[i][columnNum]=1;
                }
        }
        
        else{
            rowNum=GRInt(0,2);
            for (int i=0; i<=2; i++){
                    block[rowNum][i]=1;
            }
        }
        //Displaying the block. Just for testing.
        // for(int i =0; i<=2; i++){
        //    for(int j = 0; j<=2; j++){
        //        std::cout << block[i][j] << " ";
        //    }
        //    std::cout << std::endl;
        //}
        //Debug for block func

        //The map I will test extrapolation upon.
        //extrapolated map

        //extrapolation function
        int Er=2;
        int Ec=2;
        std::vector<std::vector<int>> extrapMap = {
                {1,1,1,1,1,1,1,1},
                {1,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,1},
                {1,1,1,1,1,1,1,1}
            };
            extrapMap[Er-1][Ec-1] = block[0][0];
            extrapMap[Er-1][Ec] = block[0][1];
            extrapMap[Er-1][Ec+1] = block[0][2];

            extrapMap[Er][Ec-1] = block[1][0];
            extrapMap[Er][Ec] = block[1][1];
            extrapMap[Er][Ec+1] = block[1][2];

            extrapMap[Er+1][Ec-1] = block[2][0];
            extrapMap[Er+1][Ec] = block[2][1];
            extrapMap[Er+1][Ec+1] = block[2][2];
            for (int i=0; i<extrapMap.size(); i++){
                for(int j=0; j<extrapMap[i].size(); j++){
                    std::cout<<extrapMap[i][j] << " ";
                }
                std::cout<< std::endl;
            }
        
    }*/

    // Now I need to generate a list of points for Er and Ec based on the size of the generated map, 
    //extrapolate that upon the map, 
    //then have that map get used. 
    //Piece of cake, just time consuming.


    //size 5=as-3
    //size 8=as-6
    //size 11=as-9



    //Basically basically, I uh, wanna have a reusable numberGen class because I ont know how to make header files.
    //I also am gonna keep the mazeData class separate so I can prevent scope issues.


    //Just a class to access a number generator to make coding faster. 
    //To use a generator call GRInt 
    //To use a mod size corrector call SizeCorr




    //maze creation data for ease of access
    class mazeData {
        public:
        numberGen g1;
        int mpSize = g1.SizeCorr(3,3,12);
        
        //creates a map that can be separated into 3x3 blocks
        //empty map vector.vvv
        //Empty map vector.^^^
        //

        void mpCreate(std::vector<std::vector<int>>& mp) {
                mp.resize(mpSize + 2, std::vector<int>(mpSize + 2, 0));
                for (int i = 0; i < mpSize + 2; i++) {
                    for (int j = 0; j < mpSize + 2; j++) {
                        if (i == 0 || i == mpSize + 1 || j == 0 || j == mpSize + 1) {
                            mp[i][j] = 1;
                        }
                    }
                }
        }
        //Map gen ^^^^^^^



        


    };

    //This is for debugging. I dont have a use yet.
    void initalization(){

    }

    void creatMap(std::vector<std::vector<int>>& map){
        mazeData h;
        blockRand2 l;
        //Creates a empty map
        h.mpCreate(map);
        //randomizes said map
        //(empty vector, size to put into )
        l.workingCombo(map, h.mpSize);
        

        std::cout<< h.mpSize << "\n" << std::endl;
    }

};

class charData{
    public:
        void initialization(){

        }
        std::string charName;
        std::vector<std::string> inventory;
        std::vector<std::vector<int>> currentMap;
};


class worldData{
    public:
        std::vector<std::vector<std::vector<int>>> worldVector;
        std::string worldSize;
        //VVVVVVVVVVVVV
        //small=3;
        //medium=6;
        //large=9;
        //extra_large=12;
        //VVVVVVVVVVVVV
        int worldSizeNum;
        
        
};

//generation of world(3-12 rooms)
class worldGen{
    public:
    numberGen nGen;
    roomGen rGen;
    worldData wData;
    
        std::vector<std::vector<int>> map1;
        std::vector<std::vector<int>> map2;
        std::vector<std::vector<int>> map3;
        std::vector<std::vector<int>> map4;
        std::vector<std::vector<int>> map5;
        std::vector<std::vector<int>> map6;
        std::vector<std::vector<int>> map7;
        std::vector<std::vector<int>> map8;
        std::vector<std::vector<int>> map9;
        std::vector<std::vector<int>> map10;
        std::vector<std::vector<int>> map11;
        std::vector<std::vector<int>> map12;

        
        void worldCreation(std::string ws){

            if (ws == "small"){
                rGen.creatMap(map1);
                rGen.creatMap(map2);
                rGen.creatMap(map3);
                wData.worldVector.push_back(map1);
                wData.worldVector.push_back(map2);
                wData.worldVector.push_back(map3);
                
            }
            else if(ws == "medium"){
                rGen.creatMap(map1);
                rGen.creatMap(map2);
                rGen.creatMap(map3);
                rGen.creatMap(map4);
                rGen.creatMap(map5);
                rGen.creatMap(map6);
                wData.worldVector.push_back(map1);
                wData.worldVector.push_back(map2);
                wData.worldVector.push_back(map3);
                wData.worldVector.push_back(map4);
                wData.worldVector.push_back(map5);
                wData.worldVector.push_back(map6);
            }
            else if(ws == "large"){
                rGen.creatMap(map1);
                rGen.creatMap(map2);
                rGen.creatMap(map3);
                rGen.creatMap(map4);
                rGen.creatMap(map5);
                rGen.creatMap(map6);
                rGen.creatMap(map7);
                rGen.creatMap(map8);
                rGen.creatMap(map9);
                wData.worldVector.push_back(map1);
                wData.worldVector.push_back(map2);
                wData.worldVector.push_back(map3);
                wData.worldVector.push_back(map4);
                wData.worldVector.push_back(map5);
                wData.worldVector.push_back(map6);
                wData.worldVector.push_back(map7);
                wData.worldVector.push_back(map8);
                wData.worldVector.push_back(map9);
            }
            else if(ws == "extra large"){
                rGen.creatMap(map1);
                rGen.creatMap(map2);
                rGen.creatMap(map3);
                rGen.creatMap(map4);
                rGen.creatMap(map5);
                rGen.creatMap(map6);
                rGen.creatMap(map7);
                rGen.creatMap(map8);
                rGen.creatMap(map9);
                rGen.creatMap(map10);
                rGen.creatMap(map11);
                rGen.creatMap(map12);
                wData.worldVector.push_back(map1);
                wData.worldVector.push_back(map2);
                wData.worldVector.push_back(map3);
                wData.worldVector.push_back(map4);
                wData.worldVector.push_back(map5);
                wData.worldVector.push_back(map6);
                wData.worldVector.push_back(map7);
                wData.worldVector.push_back(map8);
                wData.worldVector.push_back(map9);
                wData.worldVector.push_back(map10);
                wData.worldVector.push_back(map11);
                wData.worldVector.push_back(map12);
            }
            else{
                std::cout<<"ERROR. UNDEFINED WORLD SIZE. PLEASE GO TO (class worldGen/worldCreation) TO FIND A FIX.";
            };
        }
};

//iGD stands for initializing game data.
class iGD{
    public:
    numberGen numGen;
    roomGen rmGen;
    worldData wData;
    worldGen wrldGen;
        //player inputs world size.
        void playerInputWorldSizeInitialization(){
            while (true){
                std::cout << "Choose a world size: small. medium, large, or extra large: " << "[";
                std::cin >> wData.worldSize;
                std::transform(wData.worldSize.begin(),wData.worldSize.end(),wData.worldSize.begin(),::tolower);
                wrldGen.worldCreation(wData.worldSize);
                if (wData.worldSize=="small"){
                    wData.worldVector.push_back(wrldGen.map1);
                    wData.worldVector.push_back(wrldGen.map2);
                    wData.worldVector.push_back(wrldGen.map3);
                    wData.worldSizeNum=3;
                    break;
                }
                else if (wData.worldSize=="medium"){
                    wData.worldVector.push_back(wrldGen.map1);
                    wData.worldVector.push_back(wrldGen.map2);
                    wData.worldVector.push_back(wrldGen.map3);
                    wData.worldVector.push_back(wrldGen.map4);
                    wData.worldVector.push_back(wrldGen.map5);
                    wData.worldVector.push_back(wrldGen.map6);
                    wData.worldSizeNum=6;
                    break;
                }
                else if (wData.worldSize=="large"){
                    wData.worldVector.push_back(wrldGen.map1);
                    wData.worldVector.push_back(wrldGen.map2);
                    wData.worldVector.push_back(wrldGen.map3);
                    wData.worldVector.push_back(wrldGen.map4);
                    wData.worldVector.push_back(wrldGen.map5);
                    wData.worldVector.push_back(wrldGen.map6);
                    wData.worldVector.push_back(wrldGen.map7);
                    wData.worldVector.push_back(wrldGen.map8);
                    wData.worldVector.push_back(wrldGen.map9);
                    wData.worldSizeNum=9;
                    break;
                }
                else if (wData.worldSize=="extra large"){
                    wData.worldVector.push_back(wrldGen.map1);
                    wData.worldVector.push_back(wrldGen.map2);
                    wData.worldVector.push_back(wrldGen.map3);
                    wData.worldVector.push_back(wrldGen.map4);
                    wData.worldVector.push_back(wrldGen.map5);
                    wData.worldVector.push_back(wrldGen.map6);
                    wData.worldVector.push_back(wrldGen.map7);
                    wData.worldVector.push_back(wrldGen.map8);
                    wData.worldVector.push_back(wrldGen.map9);
                    wData.worldVector.push_back(wrldGen.map10);
                    wData.worldVector.push_back(wrldGen.map11);
                    wData.worldVector.push_back(wrldGen.map12);
                    wData.worldSizeNum=12;
                    break;
                }
                else{
                    std::cout<<"Please input valid size" << std::endl;
                }
            }
        }
        //generation+display.
        void worldGeneration(){
            playerInputWorldSizeInitialization();
     for (size_t mapIndex = 0; mapIndex < wData.worldVector.size(); ++mapIndex) {
        std::cout << "Map " << mapIndex + 1 << ":\n";

        for (const auto& row : wData.worldVector[mapIndex]) {
            for (int cell : row) {
                std::cout << cell << " ";
            }
            std::cout << "\n";
        }

        std::cout << "-----------------------\n";
    }
        }
        //
        //Player spawns

        void spawn(){
            while(true){
                int room=numGen.GRInt(0,wData.worldSizeNum);
                    std::vector<std::vector<int>> roomSpawn=wData.worldVector[room];
                    int rowSpawnMax=roomSpawn.size();
                    int randrow=numGen.GRInt(0,rowSpawnMax);
                    std::vector<int> row=wData.worldVector[room][randrow];
                    int pos = numGen.GRInt(0,roomSpawn.size());
                    std::vector<int> location = {room,randrow,pos};
                    if (wData.worldVector[room][randrow][pos]==0){
                        std::cout << room << std::endl;
                        std::cout << randrow << std::endl;
                        std::cout<<pos<<std::endl;
                        break;
                    }


            }
        }
};

int main(int argc, char *argv[]){
    iGD initial;
    numberGen numGen;
    roomGen rmGen;
    worldData wData;
    worldGen wrldGen;
    
    //generates the world
    initial.worldGeneration();
    initial.spawn();

    return 0;
}
