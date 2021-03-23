#include <iostream>
#include <tuple>
#include <list>
#include <ctime>
#include <unistd.h>
#include <chrono>
#include <ncurses.h>
#include "../include/7seg.h"

#define DELAY 30

// Caractéristiques des fruits 
const int NBFRUITMAX = 1;
const int PTSFRUITS = 10;

// Caractéristiques du niveau
const int LARGEUR = 40;
const int HAUTEUR = 40;
const char mur = '*';

using namespace std;
class Snake {

    public:
        Snake();
        void fillWalls();
        void defineStartPosition();
        void getInput();
        void handleBuzzer();
        static void* launchForThread(void* p);
        static void* launchForThreadBuzzer(void* p);
        void genererFruit();
        void genererCoord(int *coordx, int *coordy);
        void handleSoundLose();
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
        void afficherFruit(int x, int y);
        void clearsnake();


    private:
        // Caractéristiques du level
        char level [HAUTEUR][LARGEUR];

        // Caractéristiques du serpent 

        int taille=5;
        char direction;

        bool youLoseFlag;
        bool growFlag;

        list<tuple<int, int, const wchar_t>> coord;

        // Fruit

        tuple<int, int> coordFruit;

        // Score

        int score;
        Afficheur7Seg scoreBoard;
};


