#include "../include/Snake.h"

enum choice {play,quit};

int displayMenu() {/*
    cout <<" ______________________________________________________________________________________"<<endl;
    cout <<"|                                                                                      |"<<endl;
    cout <<"|                           SNAKE, THE ORIGINAL GAME                                   |"<<endl;
*/}

int main() {
    Snake game;
    int choice = displayMenu();
    cout<<"test"<<endl;
    switch(choice) {
        case play:
            game.defineStartPosition();
            game.fillWalls();
        case quit:
            exit(0);
    }
    return 0;
}