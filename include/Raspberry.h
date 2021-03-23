#include <iostream>
#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>


void activateVibration() {
    digitalWrite (2, HIGH);
}

void activateSound() {
    digitalWrite (1, HIGH);
}

void deActivateVibration() {
    digitalWrite (2, LOW);
}

void deActivateSound() {
    digitalWrite (1, LOW);
}

bool antiRebond(int pin, char* value, char newValue) {
    if(digitalRead(pin) == 0) {
        *value = newValue;
        for(int i=0;i<400;i++);
        if(digitalRead(pin) == 0) {
            return true;
        }
    }
    return false;
}

void handleInput (char* value) { 
    antiRebond(25, value, 'A');
        //vers le haut
    antiRebond(23, value, 'B');
        //vers le bas
    antiRebond(24, value, 'C');
        //vers la droite
    antiRebond(6, value, 'D');
        //vers la gauche
}

void initInputsOutputs() {
      pinMode(25,INPUT);
      pinMode(23,INPUT);
      pinMode(24,INPUT);
      pinMode(6,INPUT);
      pinMode(1,OUTPUT);
      pinMode(2,OUTPUT);
}