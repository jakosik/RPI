#include <iostream>
#include "include/Snake.h"

Snake::Snake() {

    fillWalls();
    defineStartPosition();

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

