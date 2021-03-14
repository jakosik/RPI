#include "../include/Snake.h"
#include "../include/MenuFunctions.h"


int displayMenu() {
    displayBorder(false);
    displayTextInMenu("SNAKE, THE ORIGINAL GAME", GREEN);
    displayTextInMenu("brought to you by Vincent and Jack", GREEN);
    displayBorder(true);
    displayTextInMenu("OPTIONS:", BLUE);
    displayTextInMenu("1. PLAY", YELLOW);
    displayTextInMenu("2. QUIT", YELLOW);
    displayBorder(true);
}


int main() {
    cout<<flush<<endl;
    system("clear");
    Snake game;
    int choice = displayMenu();
    switch(choice) {
        case play:
            game.defineStartPosition();
            game.fillWalls();
        case quit:
            exit(0);
    }
    return 0;
}

