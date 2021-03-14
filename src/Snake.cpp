#include "../include/Snake.h"
#include <ctime>
#include"../include/getKey.h"
#include <unistd.h>
#include <chrono>


Snake::Snake() {
    srand(time(NULL));

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
    tuple<char, int, char> corp;

    for(int i=19;i<23;i++) {
        this->level [20][i] = '#';
        corp = make_tuple(20, i, '#');
        coord.push_back(corp);
    }

    this->level[20][23] = '@';
    corp = make_tuple(20,23,'@');
    coord.push_back(corp);

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

void Snake::genererCoord(int *coordx, int *coordy){

    *coordx = rand()%38+1;
    *coordy = rand()%38+1;

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

void Snake::genererFruit(){
    int x,y;

    do{genererCoord(&x,&y);} 
    while(level[x][y] != ' ');

    level[x][y] = '&';

}

void majSnake(){

       for(auto runUntil = std::chrono::system_clock::now() + std::chrono::milliseconds(100); 
            std::chrono::system_clock::now() < runUntil;){               

            // toutes les 100 milisecondes, on obtient l'actualisation de l'écran

            }
        

}