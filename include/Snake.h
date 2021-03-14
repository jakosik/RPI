#include <iostream>
#include <tuple>
#include <list>


// Caractéristiques des fruits 
const int NBFRUITMAX = 1;
const int PTSFRUITS = 10;

using namespace std;
class Snake {

    public:
        Snake();
        void fillWalls();
        void defineStartPosition();
        void genererFruit();
        void genererCoord(int *coordx, int *coordy);

        void majSnake();

        void grow();

    private:
        // Caractéristiques du level
        char level [40][40];

        // Caractéristiques du serpent 

        int taille=5;
        list<tuple<char, char, char>> coord;

};


