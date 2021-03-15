#include <iostream>
#include <tuple>
#include <list>
#include <ctime>
#include <unistd.h>
#include <chrono>

// Caractéristiques des fruits 
const int NBFRUITMAX = 1;
const int PTSFRUITS = 10;
const int LARGEUR = 40;
const int HAUTEUR = 40;

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
        void displayGrid();
        void grow();
        void update();
        void handleMovement();
        void fillVoid();
        void defineSnakePosition();
        void checkHitWall(int xHead, int yHead);
        void checkSnakeCollision(int x, int y, int xHead, int yHead);
        bool isSnake(int x, int y);
        bool checkFruit(int xHead, int yHead);

    private:
        // Caractéristiques du level
        char level [HAUTEUR][LARGEUR];

        // Caractéristiques du serpent 

        int taille=5;
        char direction;

        bool youLoseFlag;
        bool growFlag;

        list<tuple<int, int, char>> coord;

        // Fruit

        tuple<int, int> coordFruit;

        // Score

        int score=0; 
};


