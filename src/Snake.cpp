#include "../include/Snake.h"
#include <ctime>
#include"../include/getKey.h"
#include <unistd.h>
#include <chrono>


Snake::Snake() {
    sauvegarderConfigTerminal();
    srand(time(NULL));
    defineStartPosition();
    this->direction='q';
    youLoseFlag = false;

}
Snake::~Snake() {
    restaurerConfigTerminal();
}

void Snake::fillVoid()  {
    for(int i=0; i<HAUTEUR;i++) {
        for(int j = 0;j<LARGEUR;j++) {
            this->level[i][j]=' ';
        }
    }
}
void Snake::displayGrid() {
    fillVoid();
    fillWalls();
    defineSnakePosition();
    system("clear");
    for(int j=0;j<HAUTEUR;j++){
        for(int i=0;i<LARGEUR;i++) {
            cout<<this->level[j][i];
        }
        cout<<endl;
    }
}
void Snake::defineSnakePosition() {
    for(list<tuple<int, int, char>>::iterator it = this->coord.begin(); it!= this->coord.end();it++) {
        this->level[get<0>((*it))][get<1>((*it))] = get<2>((*it));
    }
}
void Snake::defineStartPosition() {
    this->coord.push_back(make_tuple(20,23,'@'));
    for(int i=22;i>18;i--) {
        this->coord.push_back(make_tuple(20,i,'#'));
    }

    
    
}

void Snake::fillWalls(){
    // La fonction remplis les murs pour visuel et collisions
    for(int i=1;i<=HAUTEUR-2;i++){
        level[i][0]='|';
        level[i][LARGEUR-1]='|';
    }
    for(int j=0;j<=LARGEUR-1;j++){
        level[0][j]='_';
        level[HAUTEUR-1][j]='*';
    }
    level[0][0]=' ';
    level[0][LARGEUR-1]=' ';

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

    *coordx = rand()%(LARGEUR-2)+1;
    *coordy = rand()%(HAUTEUR-2)+1;

}
void Snake::getInput() {
    do {
        this->direction=getchar();
    } while(this->direction!='p' && !this->youLoseFlag);
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

void Snake::CheckHitWall(int xHead, int yHead) {
    if (xHead == LARGEUR-1 || yHead == HAUTEUR-1|| xHead == 0 || yHead == 0)
        this->youLoseFlag = true;
}
void Snake::checkSnakeCollision(int x, int y, int xHead, int yHead) {
}
void Snake::handleMovement()
{
    int xOld, yOld;
    if (direction == 'C' || direction == 'A' || direction == 'D' || direction == 'B') {
        for (list<tuple<int, int, char>>::iterator it = this->coord.begin(); it != this->coord.end(); it++) {
            if (get<2>((*it)) == '@') {
                yOld = get<0>((*it));
                xOld = get<1>((*it));
                switch (this->direction) {
                case 'A':
                    get<0>((*it)) = get<0>((*it)) - 1; // y=y-1, on remonte la tête
                    break;
                case 'D':
                    get<1>((*it)) = get<1>((*it)) - 1; // x=x-1, on déplace la tete vers la gauche
                    break;
                case 'C':
                    get<1>((*it)) = get<1>((*it)) + 1; // x=x+1, on déplace la tete vers la droite
                    break;
                case 'B':
                    get<0>((*it)) = get<0>((*it)) + 1; // y=y+1, on déplace la tete vers le bas
                    break;
                }
                CheckHitWall(get<1>((*it)), get<0>((*it)));
                break;
            }
        }
        int xTemp, yTemp;
        for (list<tuple<int, int, char>>::iterator it2 = this->coord.begin(); it2 != this->coord.end(); it2++) {
            if (get<2>((*it2)) != '@') {
                yTemp = get<0>((*it2));
                xTemp = get<1>((*it2));
                get<0>((*it2)) = yOld;
                get<1>((*it2)) = xOld;
                yOld = yTemp;
                xOld = xTemp;
            }
        }
    }
}
void Snake::update() {
    this->handleMovement();
    this->displayGrid();
}

void Snake::majSnake(){
        while (this->direction != 'p' && !this->youLoseFlag) {
            for(auto runUntil = std::chrono::system_clock::now() + std::chrono::milliseconds(150); 
            std::chrono::system_clock::now() < runUntil;){
                usleep(1);
                // toutes les 100 milisecondes, on obtient l'actualisation de l'écran
            }
            this->update();
        }
       
        

}