#include <iostream>
#include <tuple>
#include <list>

using namespace std;
class Snake {

    public:
        Snake();
        void fillWalls();
        void defineStartPosition();
        void getInput();
        void boucler();
        static void* launchForThread(void* p);
        void genererFruit();
        void genererCoord(int *coordx, int *coordy);

        void majSnake();

        void grow();

    private:
        // Caractéristiques du level
        char level [40][40];

        // Caractéristiques du serpent 

        int taille=5;
        char direction;
        list<tuple<char, char, char>> coord;

};


