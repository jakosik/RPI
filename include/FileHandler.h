#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int getScoreFile () {
    string firstLine;
    ifstream scoreFile ("highScore.txt", ios::in);
    if (scoreFile.is_open())
    {
        getline (scoreFile,firstLine);
        return stoi(firstLine);
    }
    else 
        return 0;
}

void writeScoreFile(int score) {
    ofstream scoreFile;
    scoreFile.open ("highScore.txt", ios::trunc);
    scoreFile << to_string(score);
    scoreFile.close();
}