#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cmath>
//weapon system




int main(){

srand(time(NULL));
//Attributes. {speed,power,damage}
std::vector<double> axe = {0,2,2};
std::vector<double> sword = {1,1,1};
std::vector<double> knife = {2,0.5,0.5};

double randomNum = rand() % 100;
//std::cout << randomNum;


//characters {speedmult, powermult, damagemult, health, armor}
std::vector<double> pc = {1, 1, 1, 50, 5};
std::vector<double> enemy ={1, 1, 1, 50, 5};


//classes {dmg add, speed add, power add, walk}
std::vector<double> barb = {5, 2.5, 10, 5};
std::vector<double> wickassa = {0, 15, 2.5, 10};
std::vector<double> captain = {5, 10, 2.5, 5};
std::vector<double> pirate = {5, 5, 7.5, 8}; 


double droll = randomNum/100;
double wroll = (randomNum+15)/100;
//double dmg = enemy[0] * droll;
//std::cout << dmg;

//int doe = enemy[0]* proll;
//std::cout << enemy[0];

//attack variability
double varAttack = rand() % 10;
double varSpeed = rand() % 5;
double varPower = rand() % 8;
double luck = varAttack + rand() % 3;

//walking
double dfrom;
double sight;
bool spot;
double anger;
double sneak;

double esight;
bool espot;
double eanger;
double esneak;



//sneaking


if (dfrom == 5){
    sneak + 1;
    anger + 1;
    }
if (dfrom < 5){
    spot = true;
    }
else if (dfrom <=8 && dfrom >= 6){
    sneak-1;
    }
    
if (dfrom == 5){
    esneak + 1;
    eanger + 1;
    }
if (dfrom < 5){
    espot = true;
    }
else if (dfrom <=8 && dfrom >= 6){
    esneak-1;
    }


double cp = rand() % 5;
double rp = rand() % 5;
double cc = rand() % 5;
double rc = rand() % 5;

std::cout << cc<<"\n";
std::cout << rc<<"\n";
std::cout << cp<<"\n";
std::cout<<  rp<<"\n";
//while (sqrt((cc + cp)^2 + (rc+rp)^2) == 2) {



//double cp = rand() % 5;
//double rp = rand() % 5;
std::vector<double> posplay = {rp,cp};



//double cc = rand() % 5;
//double rc = rand() % 5;
std::vector<double> poscomp = {rc,cc};

//} 

//std::cout << posplay[0];
//std::cout << poscomp[1];

while ((abs(rc-rp)+abs(cc-cp)) <= 2) {
    cc = rand() % 5;
    rc = rand() % 5;
    cp = rand() % 5;
    rp = rand() % 5;
    
    }
std::cout << "testing\n" << cc<<"\n";
std::cout <<rc<<"\n";
std::cout <<cp<<"\n";
std::cout <<rp<<"\n";



//system now detects location and makes sure it is >=3 blocks away. 



//fighting

//spawn




}