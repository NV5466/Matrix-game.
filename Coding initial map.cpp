
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>


//map.
int matrix[8][8] ={
    {1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1}
};
//displays map.
void displayMap(){
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
    
            
            std::cout << matrix[i][j] << "";
            }
        std::cout << std::endl;
    }
}

//intialized map. Shows the initial rv, then makes the rv 0.
void initialMap(int &rr1, int &rc1, int &rr2, int &rc2){
    matrix[rr1][rc1]=2;
    matrix[rr2][rc2]=2;

    displayMap();
}

//test for if a move is valid.
bool isValidMove(int row, int col) {
    return row > 0 && row < 7 && col >0 && col < 7; 
}

//movement selection process.
void moveSel(int &rowm, int &colm){
    bool up;
    bool right;
    bool down;
    bool left;
    int mov;
    while (true){
        if (isValidMove(rowm-1,colm) == true) {
            std::cout << "\nmove up (3)\n";
            up = true;
        }
        else {
            up = false;
        }
    
        if (isValidMove(rowm,colm+1) == true) {
            std::cout << "\nmove right (4)\n";
            right = true;
        }
        else {
            right = false;
        }
        if (isValidMove(rowm+1,colm) == true) {
            std::cout << "\nmove down (5)\n";
            down = true;
        }
        else {
            down = false;
        }
        if (isValidMove(rowm,colm-1) == true) {
            std::cout << "\nmove left (6)\n";
            left = true;
        }
        else {
            left = false;
        }
        std::cout << "\nMove in a dir: ";
        std::cin >> mov; 
        if (!std::cin) {
            std::cin.clear();  // Clears the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignores the invalid input
            std::cout << "Invalid input. Please enter a number.\n";
            displayMap();
            continue;  // Skips the rest of the loop and asks for input again
        }
        if (up==true && mov == 3){
            matrix[rowm][colm]=0;
            rowm--;
            matrix[rowm][colm]=3;
            break;
        }
        else if(right==true && mov==4){
            matrix[rowm][colm]=0;
            colm++;
            matrix[rowm][colm]=4;
            break;
        }
        else if(down==true && mov==5){
            matrix[rowm][colm]=0;
            rowm++;
            matrix[rowm][colm]=5;
            break;
        }
        else if(left==true && mov==6){
            matrix[rowm][colm]=0;
            colm--;
            matrix[rowm][colm]=6;
            break;
        }
        else {
            std::cout << "enter valid move.\n";
            displayMap();
        }
    }

}

//random position generator.
void randPos(int &rr1, int &rc1, int &rr2, int &rc2) {
    srand(time(NULL));
        rr1 = rand() % 8;
        rc1 = rand() % 8;
        rr2 = rand() % 8;
        rc2 = rand() % 8;
    
    while ((abs(rr2-rr1)+abs(rc2-rc1))<2 || rr2 == 0 || rr2==7 || rr1==0 || rr1==7 || rc1 ==0 || rc1==7|| rc2 == 0|| rc2==7){
   
        rr1 = rand() % 8;
        rc1 = rand() % 8;
        rr2 = rand() % 8;
        rc2 = rand() % 8;
    
    }
    }







int main(){
    std::cout << "************************************\n";
    std::cout << "Welcome to my infinite movement test\n";
    std::cout << "************************************\n";
    std::cout << "Enter start to begin: ";
    while (true){
        std::string s;
        std::cin >> s;
        if (s == "start"){
            break;
        }
        else if (s == "START"){
            break;
        }
        else{
            std::cout << "Enter start to begin: ";
        }
    }
    int rr1;
    int rc1;
    int rr2;
    int rc2;

    randPos(rr1,rc1,rr2,rc2);
    initialMap(rr1,rc1,rr2,rc2);
    //outputs a map with a random position.

    while (true){
        moveSel(rr1,rc1);
        displayMap();
    }

}
