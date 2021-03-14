#include <iostream>
#include "../include/Snake.h"
#include <ctime>
#include"../include/getKey.h"
#include <unistd.h>
Snake::Snake() {

    this->direction='q';
    for(int i=0; i<40;i++) {
        for(int j = 0;j<40;j++) {
            this->level[i][j]=' ';
        }
    }
    fillWalls();
    defineStartPosition();

}

void Snake::boucler(){
    int c=0;
        while(this->direction != 'p') {
            usleep(1);
        cout<<this->direction<<endl;
    }
}

void Snake::defineStartPosition() {
    for(int i=19;i<23;i++) {
        this->level [20][i] = '#';
    }
    this->level[20][23] = '@';
}

void Snake::fillWalls(){
    // La fonction remplis les murs pour visuel et collisions
    for(int i=1;i<=38;i++){
        level[i][0]='|';
        level[i][39]='|';
    }
    for(int j=0;j<=39;j++){
        level[0][j]='_';
        level[39][j]='*';
    }
    level[0][0]=' ';
    level[0][39]=' ';

    // La matrice ressemble alors à :

/*

 __________________
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
********************

**/


}
void Snake::getInput() {
    sauvegarderConfigTerminal();
    do {
        this->direction=getchar();
    } while(this->direction!='p');
    restaurerConfigTerminal();
}
void* Snake::launchForThread(void* p) {
    static_cast<Snake*>(p)->getInput();
}


