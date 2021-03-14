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
        void getInput();
        static void* launchForThread(void* p);
        void genererFruit();
        void genererCoord(int *coordx, int *coordy);

        void majSnake();
        void displayGrid(bool init);
        void grow();
        void update();
        void handleMovement();
        void fillVoid();
        void defineSnakePosition();

    private:
        // Caractéristiques du level
        char level [40][40];

        // Caractéristiques du serpent 

        int taille=5;
        char direction;
        list<tuple<int, int, char>> coord;

};


