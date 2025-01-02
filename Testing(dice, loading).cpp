
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>
#include <chrono>


void d2(int nor){
    srand(time(NULL));
    for (int i=0; i<nor; i++){
        std::cout<<"roll "<<i+1<<": "<<(rand()%2)+1<< "\n";
    }}
void d3(int nor){
    srand(time(NULL));
    for (int i=0; i<nor; i++){
        std::cout<<"roll "<<i+1<<": "<<(rand()%3)+1<< "\n";
    }}
void d4(int nor){
    srand(time(NULL));
    for (int i=0; i<nor; i++){
        std::cout<<"roll "<<i+1<<": "<<(rand()%4)+1<< "\n";
    }}
void d5(int nor){
    srand(time(NULL));
    for (int i=0; i<nor; i++){
        std::cout<<"roll "<<i+1<<": "<<(rand()%5)+1<< "\n";
    }}
void d6(int nor){
    srand(time(NULL));
    for (int i=0; i<nor; i++){
        std::cout<<"roll "<<i+1<<": "<<(rand()%6)+1<< "\n";
    }}
void d7(int nor){
    srand(time(NULL));
    for (int i=0; i<nor; i++){
        std::cout<<"roll "<<i+1<<": "<<(rand()%7)+1<< "\n";
    }}
void d8(int nor){
    srand(time(NULL));
    for (int i=0; i<nor; i++){
        std::cout<<"roll "<<i+1<<": "<<(rand()%8)+1<< "\n";
    }}
void d9(int nor){
    srand(time(NULL));
    for (int i=0; i<nor; i++){
        std::cout<<"roll "<<i+1<<": "<<(rand()%9)+1<< "\n";
    }}
void d10(int nor){
    srand(time(NULL));
    for (int i=0; i<nor; i++){
        std::cout<<"roll "<<i+1<<": "<<(rand()%10)+1<< "\n";
    }}
void d11(int nor){
    srand(time(NULL));
    for (int i=0; i<nor; i++){
        std::cout<<"roll "<<i+1<<": "<<(rand()%11)+1<< "\n";
    }}


void d12(int nor){
    srand(time(NULL));
    for (int i=0; i<nor; i++){
        std::cout<<"roll "<<i+1<<": "<<(rand()%12)+1<< "\n";
    }}
//the testing stuff ^^^^^
//singular dice rolls vvvvv
int sd13(){
    srand(time(NULL));
    return ((rand()%13)+1);}
int sd12(){
    srand(time(NULL));
    return ((rand()%12)+1);}
int sd11(){
    srand(time(NULL));
    return ((rand()%11)+1);}
int sd10(){
    srand(time(NULL));
    return ((rand()%10)+1);}
int sd9(){
    srand(time(NULL));
    return ((rand()%9)+1);}
int sd8(){
    srand(time(NULL));
    return ((rand()%8)+1);}
int sd7(){
    srand(time(NULL));
    return ((rand()%7)+1);}
int sd6(){
    srand(time(NULL));
    return ((rand()%6)+1);}
int sd5(){
    srand(time(NULL));
    return ((rand()%5)+1);}
int sd4(){
    srand(time(NULL));
    return ((rand()%4)+1);}
int sd3(){
    srand(time(NULL));
    return ((rand()%3)+1);}
int sd2(){
    srand(time(NULL));
    return ((rand()%2)+1);}



//int d12 (){
// srand(time(NULL))};
// return (rand()%12)+1;
//}
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>





int main() {
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
        } }

    bool check1 =0;
    bool check2 =0;
    bool check3 =0;
    bool check4 =0;


    int RanPosCho=1;
    int charcterVars=1;
    int mapIlzd=1;
    int classCho=1;
    if (RanPosCho==1){
        check1=1;
    }
    if (charcterVars==1){
        check2=1;
    }
    if (mapIlzd==1){
        check3=1;
    }
    if (classCho==1){
        check4=1;
    }

    if (check1==1 && check2==1 && check3==1 && check4==1){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<< "[*---]\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<< "[**--]\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<< "[***-]\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<< "[****]\n";
    }
    else{
        std::cout << "ERROR, system fault. Ending program.";
        exit(0);
    }
    std::vector<char> ast;






    int mov;
    while (mov < 3){
        mov = sd6();
        }
    //std::cout << mov;
    

    
    return 0;
}
