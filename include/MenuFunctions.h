#include "stdlib.h"
#include <iostream>
using namespace std;

enum choice {play,quit};
enum color {RED, YELLOW, NORMAL, GREEN, BLUE };
void displayBorder(bool separator) {
    string conditionnalPart = separator?"|":" ";
    cout <<conditionnalPart<<"______________________________________________________________________________________"<<conditionnalPart<<endl;
}

string colorOutput(int color) {
    switch (color) {
        case RED:
            return string ("\033[0;31m");
        case NORMAL:
            return string ("\033[0m");
        case YELLOW:
            return string ("\033[0;33m");
        case GREEN:
            return string ("\033[0;32m");
        case BLUE: 
            return string ("\033[0;34m");
    }
    
}
int displayMenu() {
    displayBorder(false);
    displayTextInMenu("SNAKE, THE ORIGINAL GAME", GREEN);
    displayBorder(true);
    displayTextInMenu("OPTIONS:", BLUE);
    displayTextInMenu("1. PLAY", YELLOW);
    displayTextInMenu("2. QUIT", YELLOW);
    displayBorder(true);
    int retour;
    cin >> retour;
    return retour;
}
void displayTextInMenu(string toDisplay, int color = NORMAL){
    int totalSpaces = 86 - toDisplay.size(); 
    string secondSpace = (totalSpaces%2==0) ? string(int(totalSpaces/2), ' '):string(int(totalSpaces/2)+1, ' ');
    cout<<"|"<< string(int(totalSpaces/2), ' ')<<colorOutput(color)<< toDisplay<<colorOutput(NORMAL)
    <<secondSpace<<"|"<<endl;
}
