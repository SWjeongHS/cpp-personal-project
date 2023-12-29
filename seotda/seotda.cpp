#include <iostream>
#include <thread>
#include <cstdlib>//for random
#include <ctime>
using namespace std;


int main(void){
    int card[10][2];//1~10 month * pair
    int tmpnum=0,tmpnum2=-1;

    srand((unsigned int)time(NULL));
    tmpnum = rand()%20;
    card[tmpnum/2][tmpnum%2]=1;
    while(tmpnum!=tmpnum2){
        tmpnum2 = rand()%20;
    }
    return 0;
}
