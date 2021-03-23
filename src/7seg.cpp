#include "../include/7seg.h"
#include <iostream>
#include "string.h"

using namespace std;
Afficheur7Seg::Afficheur7Seg() {
  this->fileDesc = wiringPiI2CSetup(0x70);
  wiringPiI2CWrite(this->fileDesc, 0x21); //on
  wiringPiI2CWrite(this->fileDesc, 0x81); //display on + blinking off 
  wiringPiI2CWrite(this->fileDesc, 0xEF); //duty cycle max, donc brightness au max.
  clear();
  ecrireBitsAEnvoyer(0,0);
  ecrireBitsAEnvoyer(1,0);
  ecrireBitsAEnvoyer(2,0);
  ecrireBitsAEnvoyer(3,0);
  ecrireRegistres();
}


void Afficheur7Seg::ecrireRegistres() { 
  uint8_t addr = (uint8_t) 0x00;	 //addresse du registre
  uint8_t i=0; 
  for(i=0 ; i<4 ; i++) { 
	if(i==2)
      {
        wiringPiI2CWriteReg8(this->fileDesc, addr++, 0b00); // on met les deux points à 0 car on ne veut pas de double points.
        addr++;
      }
	        
        wiringPiI2CWriteReg8(this->fileDesc, addr++, chiffres7Segments[i]);
        addr++;
  }  
} 

void Afficheur7Seg::clear() { 
  uint8_t i=0; 
  for (i=0; i<4; i++) { 
    chiffres7Segments[i] = 0; 
  } 
} 

void Afficheur7Seg::ecrireBitsAEnvoyer(uint8_t indexNumero, uint8_t chiffre) {
  if(indexNumero <=9)
  chiffres7Segments[indexNumero] = nombres[chiffre];
}



void Afficheur7Seg::entrerScore(int score) {
  int i=3;
    do {
        int mod = score% 10;
        ecrireBitsAEnvoyer(i,mod);
        score = score / 10;
      i--;
    } while(score > 0 && i>=0);
    ecrireRegistres();
}
