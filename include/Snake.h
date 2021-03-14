#include <iostream>
#include<list>
#include <tuple>
using namespace std;
class Snake {

    public:
        Snake();
        void fillWalls();
        void defineStartPosition();
        void getInput();
        void boucler();
        static void* launchForThread(void* p);
    private:
        // Caractéristiques du level
        char level [40][40];

        // Caractéristiques du serpent 
        int taille;
        char direction;
};


