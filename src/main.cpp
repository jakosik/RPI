#include "../include/Snake.h"
#include "../include/MenuFunctions.h"
#include <thread>
#include"../include/getKey.h"


int main() {
    cout<<flush<<endl;
    system("clear");
    Snake game;
    int choice = displayMenu()-1;
    int retSnake, retSon;
    switch(choice) {
        case play:
            pthread_t snakeThread,buzzerThread;
            sauvegarderConfigTerminal();
            retSon = pthread_create(&buzzerThread,NULL, Snake::launchForThreadBuzzer, &game);
            retSnake = pthread_create(&snakeThread,NULL, Snake::launchForThread, &game);
            game.majSnake();
            restaurerConfigTerminal();
            pthread_join(retSon, NULL);
            pthread_join(retSnake, NULL);
            usleep(500000);
            system("clear");
            displayLoseMenu(game.getScore());
        case quit:
            exit(0);
    }
    return 0;
}
