#include "../include/Snake.h"
#include <ctime>
#include"../include/getKey.h"
#include <unistd.h>
#include <chrono>


Snake::Snake() {
    srand(time(NULL));

    this->direction='q';
    displayGrid(true);
    

}

void Snake::fillVoid()  {
    for(int i=0; i<40;i++) {
        for(int j = 0;j<40;j++) {
            this->level[i][j]=' ';
        }
    }
}

void Snake::displayGrid(bool init = false) {
    fillVoid();
    fillWalls();
    init?defineStartPosition(): defineSnakePosition();
    system("clear");
    for(int j=0;j<40;j++){
        for(int i=0;i<40;i++) {
            cout<<this->level[j][i];
        }
        cout<<endl;
    }
}

void Snake::defineSnakePosition() {

}
void Snake::defineStartPosition() {
    tuple<char, int, char> corp;

    for(int i=19;i<23;i++) {
        this->level [20][i] = '#';
        this->coord.push_back(make_tuple(20,i,'#'));
    }

    this->level[20][23] = '@';
    this->coord.push_back(make_tuple(20,23,'@'));
    
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

    do{
        genererCoord(&x,&y);
    } while(level[x][y] != ' ');
    level[x][y] = '&';

}

void Snake::handleMovement(){
    for(list<tuple<int, int, char>>::iterator it = this->coord.begin(); it!= this->coord.end();it++) {
        if(get<2>((*it)) == '@') {

        }
    }
}

void Snake::update() {
    this->displayGrid();

}

void Snake::majSnake(){
        this->displayGrid(true);
        while (this->direction != 'p') {
            for(auto runUntil = std::chrono::system_clock::now() + std::chrono::milliseconds(100); 
            std::chrono::system_clock::now() < runUntil;){
                usleep(1);
                // toutes les 100 milisecondes, on obtient l'actualisation de l'écran
            }
            this->update();

        }
       
}