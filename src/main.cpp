#include "../include/Snake.h"
#include "../include/MenuFunctions.h"
#include <thread>

int displayMenu() {
    displayBorder(false);
    displayTextInMenu("SNAKE, THE ORIGINAL GAME", GREEN);
    displayTextInMenu("brought to you by Vincent and Jack", GREEN);
    displayBorder(true);
    displayTextInMenu("OPTIONS:", BLUE);
    displayTextInMenu("1. PLAY", YELLOW);
    displayTextInMenu("2. QUIT", YELLOW);
    displayBorder(true);
    int retour;
    cin >> retour;
    return retour;
}


int main() {
    cout<<flush<<endl;
    system("clear");
    Snake game;
    int choice = displayMenu()-1;
    int retSnake;
    switch(choice) {
        case play:
            game.defineStartPosition();
            game.fillWalls();
            pthread_t snakeThread;
            retSnake = pthread_create(&snakeThread,NULL, Snake::launchForThread, &game);
            game.majSnake();
            

        case quit:
            exit(0);
    }
    return 0;
}

