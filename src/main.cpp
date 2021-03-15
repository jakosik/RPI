#include "../include/Snake.h"
#include "../include/MenuFunctions.h"
#include <thread>

int main() {
    cout<<flush<<endl;
    system("clear");
    Snake game;
    int choice = displayMenu()-1;
    int retSnake;
    switch(choice) {
        case play:
            pthread_t snakeThread;
            retSnake = pthread_create(&snakeThread,NULL, Snake::launchForThread, &game);
            game.majSnake();
            

        case quit:
            exit(0);
    }
    return 0;
}

