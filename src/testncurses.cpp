#include "../include/Snake.h"
#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include <cstdlib>

#define _XOPEN_SOURCE 1
#define _XOPEN_SOURCE_EXTENDED 1
#define _POSIX_C_SOURCE 200809L


using namespace std;

int maxhaut = HAUTEUR;
int maxlarg = LARGEUR;

int delay = 3000;

char mur = (char)219;


void InitGameWindow(){ 

    setlocale(LC_ALL,"");
	initscr(); // initialise the screen
	nodelay(stdscr,TRUE);
	keypad(stdscr, true);

    cbreak();

    timeout(10);

	noecho();
	curs_set(0);

	getmaxyx(stdscr, maxhaut, maxlarg); // define dimensions of game window
}

void Murs(){


    // Construction des murs droits et gauche


    for(int i=0; i < LARGEUR; i++){
        move(0,i);
        addch(mur);
        usleep(delay);
    }

    move(41,41);

    for(int i=0; i < LARGEUR; i++){
        move(LARGEUR-1,i);
        addch(mur);
        usleep(delay);
    }

    move(41,41);

    // Construction des murs bas et haut

    for(int j=0; j < HAUTEUR; j++){
        move(j,0);
        addch(mur);
        usleep(delay);
    }

    move(41,41);

    for(int j=0; j < HAUTEUR; j++){
        move(j,HAUTEUR-1);
        addch(mur);
        usleep(delay);
    }

    move(41,41);

}

void Snake(){

    mvaddwstr(5,10,L"\x23E3");

    for(int s=5; s < 10; s++){
        mvaddwstr(5,s,L"\x25C8");
        usleep(delay);
    }
}


int main(){
    setlocale(LC_ALL, "");
    InitGameWindow();

    clear();

    Murs();
    Snake();


    move(45,45);

    refresh();

    return(0);

}

















