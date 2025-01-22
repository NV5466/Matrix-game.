#include <iostream>
#include <vector>
#include <random>

int GRInt(int min, int max){
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(min,max);
    return dist(engine);

}

class generateMap{
    public:
    //This class is for accessing members used for randomizing parts of a map room.
    class blockRand2{
        public:



        std::vector<std::vector<int>> blockRandiC2(){
            std::vector<std::vector<int>> block = {
                {0,0,0},
                {0,0,0},
                {0,0,0}
            };
            bool isCol = GRInt(0,1);
            unsigned int columnNum;
            unsigned int rowNum;
            if (isCol == 1){
                columnNum = GRInt(0,2);
                for ( unsigned int i=0; i<=2; i++){
                        block[i][columnNum]=1;
                    }
                    int rNum=GRInt(0,2);
                    block[rNum][columnNum]=0;
            }
            
            else{
                rowNum=GRInt(0,2);
                for (unsigned int i=0; i<=2; i++){
                        block[rowNum][i]=1;
                }
                int cNum=GRInt(0,2);
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
        void workingCombo(std::vector<std::vector<int>>& y, int size){
            switch(size){
                case(3):
                    change(y,blockRandiC2(),2,2);
                    break;
                case(6):
                    change(y,blockRandiC2(),2,2);
                    change(y,blockRandiC2(),2,5);
                    change(y,blockRandiC2(),5,2);
                    change(y,blockRandiC2(),5,5);
                    break;
                case(9):   
                    change(y,blockRandiC2(),2,2);
                    change(y,blockRandiC2(),2,5);
                    change(y,blockRandiC2(),2,8);
                    change(y,blockRandiC2(),5,2);
                    change(y,blockRandiC2(),5,5);
                    change(y,blockRandiC2(),5,8);
                    change(y,blockRandiC2(),8,2);
                    change(y,blockRandiC2(),8,5);
                    change(y,blockRandiC2(),8,8);
                    break;
                case(12):
                    change(y,blockRandiC2(),2,2);
                    change(y,blockRandiC2(),2,5);
                    change(y,blockRandiC2(),2,8);
                    change(y,blockRandiC2(),2,11);

                    change(y,blockRandiC2(),5,2);
                    change(y,blockRandiC2(),5,5);
                    change(y,blockRandiC2(),5,8);
                    change(y,blockRandiC2(),5,11);

                    change(y,blockRandiC2(),8,2);
                    change(y,blockRandiC2(),8,5);
                    change(y,blockRandiC2(),8,8);
                    change(y,blockRandiC2(),8,11);

                    change(y,blockRandiC2(),11,2);
                    change(y,blockRandiC2(),11,5);
                    change(y,blockRandiC2(),11,8);
                    change(y,blockRandiC2(),11,11);
                    break;
                default:
                    std::cout << "ERROR ERROR. UNDEFINED MAP SIZE. PLEASE GO TO class (blockRand2) to check for cause";
                    break;
            }
        }

        
        void change(std::vector<std::vector<int>>& x,std::vector<std::vector<int>> blk, unsigned int row, unsigned int col){
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


    class numberGen{
        public:
        int GRInt(int min, int max){
            std::random_device rd;
            std::mt19937 engine(rd());
            std::uniform_int_distribution<int> dist(min, max);
            return dist(engine);
        }
        //
        int SizeCorr(int m, int min, int max){
            while(true){
                int size = GRInt(min,max);
                if(size % m == 0){
                    return size;
                    break;
                }
            }
        }
    };


    //maze creation data for ease of access
    class mazeData {
        public:
        numberGen g1;
        int mpSize = g1.SizeCorr(3,3,12);
        
        //creates a map that can be separated into 3x3 blocks
        //empty map vector.vvv
        //Empty map vector.^^^
        //

        void mpCreate(std::vector<std::vector<int>>& mp){
            std::vector<int> row;
            for(int i=0; i<mpSize+2; i++){
                row.clear();
                for(int j=0; j<mpSize+2; j++){
                    if(i==0 || i==mpSize+1 || j==0 || j==mpSize+1){
                        row.push_back(1);
                    }
                    else{
                        row.push_back(0);
                    }
                    std::cout << row[j] << " ";
                    //outputs row variables
                }
                mp.push_back(row);
                std::cout << std::endl;
            }
        }
        //Map gen ^^^^^^^



        


    };

    //This is for debugging. I dont have a use yet.
    void initalization(){

    }



    void creatMap(std::vector<std::vector<int>> map){
        mazeData h;
        blockRand2 l;
        //Creates a empty map
        h.mpCreate(map);
        //randomizes said map
        //(empty vector, size to put into )
        l.workingCombo(map, h.mpSize);
        

        std::cout<< h.mpSize;
    }

};

int main(){
    generateMap l;
    std::vector<std::vector<int>> map4;
    l.creatMap(map4);
    
}
