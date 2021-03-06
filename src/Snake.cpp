#include "../include/Snake.h"
 #include "../include/Raspberry.h"



void InitGameWindow(){ 

    setlocale(LC_ALL,"");
	initscr(); // initialise the screen
	nodelay(stdscr,TRUE);
	keypad(stdscr, true);

    cbreak();


	noecho();
	curs_set(0);

}

Snake::Snake() {
    this->score = 0;
    wiringPiSetup ();
    initInputsOutputs();
    growFlag=false;
    srand(time(NULL));
    defineStartPosition();
    this->direction='q';
    youLoseFlag = false;

}
Snake::~Snake() {
    this->scoreBoard.shutdown();
}


void Snake::handleBuzzer() {
    do {
        if(this->growFlag) {
            activateVibration();
            usleep(300000);
            deActivateVibration();
        }
    } while(this->direction!='p' && !this->youLoseFlag);
}

void* Snake::launchForThreadBuzzer(void* p) {
    static_cast<Snake*>(p)->handleBuzzer();
    return NULL;
}

void Snake::defineStartPosition() {
    this->coord.push_back(make_tuple(20,23, '@'));
    for(int i=22;i>18;i--) {
        this->coord.push_back(make_tuple(20,i, '#'));
    }
    
}

void Snake::getInput() {
    do {
        handleInput(&(this->direction));
    } while(this->direction!='p' && !this->youLoseFlag);
}
void* Snake::launchForThread(void* p) {
    static_cast<Snake*>(p)->getInput();
    return NULL;
}


void Snake::genererCoord(int *coordx, int *coordy){

    *coordx = rand()%(LARGEUR-2)+1;
    *coordy = rand()%(HAUTEUR-2)+1;

}

void Snake::genererFruit(){
    int x,y;

    do{
        genererCoord(&x,&y);
    } while(!isSnake(x,y));

    coordFruit = make_tuple(x,y);

    afficherFruit(x,y);
}

bool Snake::isSnake(int x, int y){
    bool confirmation = true; // Bool qui dit si on est dans serpent ou pas
    for(auto itcoord = this->coord.begin(); itcoord != this->coord.end(); itcoord++){
        if(get<0>((*itcoord)) == y || get<1>((*itcoord)) == x){
            confirmation=false;
        }
    }
    return(confirmation);
}

void Snake::grow(){
    growFlag=true;
    genererFruit();
    score+=10;
    this->scoreBoard.displayScore(score);
    
}

void Snake::checkHitWall(int xHead, int yHead) {
    if (xHead == LARGEUR-1 || yHead == HAUTEUR-1|| xHead == 0 || yHead == 0)
        this->youLoseFlag = true;
}
void Snake::checkSnakeCollision(int x, int y, int xHead, int yHead) {
    if(xHead==x && yHead ==y)
        this->youLoseFlag = true;
}

bool Snake::checkFruit(int xHead, int yHead){

    int xFruit = get<0>(coordFruit);
    int yFruit = get<1>(coordFruit);

    return(xHead == xFruit && yHead == yFruit);
}

void Snake::handleMovement(){
    int xOld, yOld,xHead,yHead;
    if (direction == 'C' || direction == 'A' || direction == 'D' || direction == 'B') {
        for (auto it = this->coord.begin(); it != this->coord.end(); it++) {
            if (get<2>((*it)) == '@') {
                yOld = get<0>((*it));
                xOld = get<1>((*it));
                switch (this->direction) {
                case 'A':
                    get<0>((*it)) = get<0>((*it)) - 1; // y=y-1, on remonte la t??te
                    break;
                case 'D':
                    get<1>((*it)) = get<1>((*it)) - 1; // x=x-1, on d??place la tete vers la gauche
                    break;
                case 'C':
                    get<1>((*it)) = get<1>((*it)) + 1; // x=x+1, on d??place la tete vers la droite
                    break;
                case 'B':
                    get<0>((*it)) = get<0>((*it)) + 1; // y=y+1, on d??place la tete vers le bas
                    break;
                }
                xHead = get<1>((*it));
                yHead = get<0>((*it));
                checkHitWall(xHead, yHead);
                if(checkFruit(xHead,yHead)){
                    grow();
                }
                break;
            }
        }
        int xTemp, yTemp; 
        for (auto it2 = this->coord.begin(); it2 != this->coord.end(); it2++) {
            if (get<2>((*it2)) != '@') {
                yTemp = get<0>((*it2));
                xTemp = get<1>((*it2));
                get<0>((*it2)) = yOld;
                get<1>((*it2)) = xOld;
                checkSnakeCollision(xOld,yOld,xHead,yHead);
                yOld = yTemp;
                xOld = xTemp;
                if(growFlag){
                    this->coord.push_back(make_tuple(yOld,xOld,'#'));
                    growFlag=false;
                }
            }
        }
    }
}

void Snake::handleSoundLose() {
    if(this->youLoseFlag) {
        activateSound();
        usleep(700000);
        deActivateSound();
    }
}
void Snake::majSnake(){
    InitGameWindow();
    genererFruit();
    this->fillWalls();
        while (this->direction != 'p' && !this->youLoseFlag) {
            for(auto runUntil = std::chrono::system_clock::now() + std::chrono::milliseconds(100); 
            std::chrono::system_clock::now() < runUntil;){
                usleep(1);
                // toutes les 100 milisecondes, on obtient l'actualisation de l'??cran
            }
            this->update();
        }
        this->handleSoundLose();

}

// ****************************************** OPTION GRAPHIQUE **********************//

void Snake::fillWalls(){
    // La fonction remplit les murs pour visuel et collisions

    for(int i=0; i < LARGEUR; i++){
        move(0,i);
        addch(mur);
        usleep(DELAY);
    }

    move(LARGEUR+1,HAUTEUR+1);

    for(int i=0; i < LARGEUR; i++){
        move(HAUTEUR-1,i);
        addch(mur);
        usleep(DELAY);
    }

    move(LARGEUR+1,HAUTEUR+1);

    // Construction des murs bas et haut

    for(int j=0; j < HAUTEUR; j++){
        move(j,0);
        addch(mur);
        usleep(DELAY);
    }

    move(LARGEUR+1,HAUTEUR+1);

    for(int j=0; j < HAUTEUR; j++){
        move(j,LARGEUR-1);
        addch(mur);
        usleep(DELAY);
    }

    move(LARGEUR+1,HAUTEUR+1);

    // La matrice ressemble alors ?? :

/*

********************
*                  *
*                  *
*                  *
*                  *
*                  *
*                  *
*                  *
********************

**/

}

void Snake::defineSnakePosition() {
    for(auto it = this->coord.begin(); it!= this->coord.end();it++) {
        move(get<0>((*it)), get<1>((*it)));
        addch(get<2>((*it)));
        usleep(DELAY);
    }
}

void Snake::clearsnake(){
    for(auto it = this->coord.begin(); it!= this->coord.end();it++) {
        move(get<0>((*it)), get<1>((*it)));
        addch(' ');
    }

}

void Snake::update() {
    this->clearsnake();
    this->handleMovement();
    this->defineSnakePosition();
    refresh();
}


void Snake::afficherFruit(int x, int y){
    move(y,x);
    addch('&');
}

int Snake::getScore(){
    return score;
}

