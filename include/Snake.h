#include <iostream>
using namespace std;
class Snake {

    public:
        Snake();
        void fillWalls();
        void defineStartPosition();

    private:
        // Caractéristiques du level
        char level [40][40];

        // Caractéristiques du serpent 
        int taille;

};


