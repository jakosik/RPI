#include <iostream>
#include <tuple>
#include <list>
#include <ctime>
#include <unistd.h>
#include <chrono>
#include <ncurses.h>
#include "../include/Afficheur7seg.h"
#define DELAY 30

// Caractéristiques des fruits 
const int NBFRUITMAX = 1;
const int PTSFRUITS = 10;

// Caractéristiques du niveau
const int LARGEUR = 80;
const int HAUTEUR = 30;
const char mur = '*';

using namespace std;
class Snake {

    public:
        Snake();
        ~Snake();
        int getScore();
        void majSnake();
        static void* launchForThread(void* p);
        static void* launchForThreadBuzzer(void* p);
    private:
        // Caractéristiques du serpent 
        void fillWalls();
        void defineStartPosition();
        void getInput();
        void handleBuzzer();
        void genererFruit();
        void genererCoord(int *coordx, int *coordy);
        void handleSoundLose();
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
        void afficherFruit(int x, int y);
        void clearsnake();
        char direction;
        bool youLoseFlag;
        bool growFlag;
        list<tuple<int, int, char>> coord;

        // Fruit

        tuple<int, int> coordFruit;

        // Score

        int score;
        Afficheur7Seg scoreBoard;
};


