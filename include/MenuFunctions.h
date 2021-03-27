#include "stdlib.h"
#include "FileHandler.h"
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
    return "";
    
}

void displayTextInMenu(string toDisplay, int color = NORMAL){
    int totalSpaces = 86 - toDisplay.size(); 
    string secondSpace = (totalSpaces%2==0) ? string(int(totalSpaces/2), ' '):string(int(totalSpaces/2)+1, ' ');
    cout<<"|"<< string(int(totalSpaces/2), ' ')<<colorOutput(color)<< toDisplay<<colorOutput(NORMAL)
    <<secondSpace<<"|"<<endl;
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

void displayLoseMenu(int score) {
    if(score<getScoreFile()) {
        displayBorder(false);
        displayTextInMenu("YOU LOSE", RED);
        displayBorder(true);
        displayTextInMenu("COME ON I KNOW YOU CAN DO BETTER", BLUE);
        displayTextInMenu("YOU ACTUALLY MANAGED TO GET THIS HIGHSCORE: "+ to_string(score), BLUE);
        displayTextInMenu("BUT THERE IS STILL ROOM FOR IMPROVEMENT, COME SEE US AGAIN, BYE", BLUE);
        displayTextInMenu("CURRENT RECORD IS " + to_string(getScoreFile()) , BLUE);
        displayTextInMenu("YOU CAN BEAT IT, NEVER SAY NEVER", BLUE);
        displayTextInMenu("WHEN THERE'S LIFE, THERE'S HOPE", BLUE);
        displayTextInMenu("WHEN THERE IS A WILL THERE IS A WAY", BLUE);
        displayBorder(true);
    }
    else {
        displayBorder(false);
        displayTextInMenu("CONGRATULATIONS!!", GREEN);
        displayBorder(true);
        displayTextInMenu("YOU MANAGED TO BEAT THE CURRENT RECORD !", BLUE);
        displayTextInMenu("YOU ACTUALLY MANAGED TO GET THIS HIGHSCORE: "+ to_string(score), BLUE);
        displayTextInMenu("YOU'RE GOOD, BUT DON'T GET TOO CONFIDENT", BLUE);
        displayTextInMenu("THE OLD RECORD WAS " + to_string(getScoreFile()) , BLUE);
        displayBorder(true);
        writeScoreFile(score);
    }
    
}
