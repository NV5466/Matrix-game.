#include <iostream>
#include <vector>
#include <random>
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



int GRInt(int min, int max){
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(min,max);
    return dist(engine);

}

//Testing pass by reference for a randomization for the map.
class blockRand2{
    public:



    void blockRandiC2(std::vector<std::vector<int>> x,int size){
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
        int rt;
    }
    
    void change(std::vector<std::vector<int>>& x,std::vector<<std::vector<int>>& block, int Er, int Ec){
        x[Er-1][Ec-1] = block[0][0];
        x[Er-1][Ec] = block[0][1];
        x[Er-1][Ec+1] = block[0][2];

        x[Er][Ec-1] = block[1][0];
        x[Er][Ec] = block[1][1];
        x[Er][Ec+1] = block[1][2];

        x[Er+1][Ec-1] = block[2][0];
        x[Er+1][Ec] = block[2][1];
        x[Er+1][Ec+1] = block[2][2];
    }
};




//Code that is all bunched together with ducttape and sticks.
void blockRan2(){
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
    
}

// Now I need to generate a list of points for Er and Ec based on the size of the generated map, 
//extrapolate that upon the map, 
//then have that map get used. 
//Piece of cake, just time consuming.


//size 5=as-3
//size 8=as-6
//size 11=as-9


int main(){

    //displays extrap map in int main
    //testing for size
    for (int i=0; i<extrapMap.size(); i++){
        for (int j=0; j<extrapMap[i].size(); j++){
            std::cout<<extrapMap[i][j]<< " ";
        }
        std::cout << std::endl;
    }
    //displays extrap map^^^^
    //

    std::cout<<extrapMap.size();

    //my value to test while creating the pbr func for block rand.
    int actualSize = extrapMap.size() - 2;


    blockRand2 h;
    h.blockRandiC2();














    return 0;


}
