#include "../include/Snake.h"
#include "../include/MenuFunctions.h"
#include <thread>
#include"../include/getKey.h"


int main() {
    cout<<flush<<endl;
    system("clear");
    Snake game;
    int retSnake, retSon;
    int choice = highscore;
    while(choice != quit && choice != play)  {
        choice = displayMenu()-1;
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
            break;
        case highscore:
            displayMenuScore();
            break;
        case quit:
            exit(0);
            break;
        default:
            break;
    }
    }
    return 0;
}
