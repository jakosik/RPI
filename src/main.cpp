#include "../include/Snake.h"
#include "../include/MenuFunctions.h"
#include <thread>
#include"../include/getKey.h"


int main() {
    cout<<flush<<endl;
    system("clear");
    Snake game;
    int choice = displayMenu()-1;
    int retSnake;
    switch(choice) {
        case play:
            pthread_t snakeThread;
            sauvegarderConfigTerminal();
            retSnake = pthread_create(&snakeThread,NULL, Snake::launchForThread, &game);
            game.majSnake();
            restaurerConfigTerminal();
        case quit:
            exit(0);
    }
    return 0;
}
