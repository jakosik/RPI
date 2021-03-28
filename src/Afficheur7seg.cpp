#include "../include/Afficheur7seg.h"
#include <iostream>
#include "string.h"

using namespace std;
Afficheur7Seg::Afficheur7Seg() {
  this->fileDesc = wiringPiI2CSetup(0x70);
  wiringPiI2CWrite(this->fileDesc, 0x21); //on
  wiringPiI2CWrite(this->fileDesc, 0x81); //display on + blinking off 
  wiringPiI2CWrite(this->fileDesc, 0xEF); //duty cycle max, donc brightness au max.
  clear();
  writeBitsToSend(0,0);
  writeBitsToSend(1,0);
  writeBitsToSend(2,0);
  writeBitsToSend(3,0);
  writeRegisters();
}
void Afficheur7Seg::shutdown() {
   uint8_t addr = (uint8_t) 0x00;	 //addresse du registre
  uint8_t i=0; 
  for(i=0 ; i<4 ; i++) { 
	if(i==2)
      {
        wiringPiI2CWriteReg8(this->fileDesc, addr++, 0b00); // on met les deux points à 0 car on ne veut pas de double points.
        addr++;
      }
	        
        wiringPiI2CWriteReg8(this->fileDesc, addr++, 0);
        addr++;
  }  
}

void Afficheur7Seg::writeRegisters() { 
  uint8_t addr = (uint8_t) 0x00;	 //addresse du registre
  uint8_t i=0; 
  for(i=0 ; i<4 ; i++) { 
	if(i==2)
      {
        wiringPiI2CWriteReg8(this->fileDesc, addr++, 0b00); // on met les deux points à 0 car on ne veut pas de double points.
        addr++;
      }
	        
        wiringPiI2CWriteReg8(this->fileDesc, addr++, digits7Segments[i]);
        addr++;
  }  
} 

void Afficheur7Seg::clear() { 
  uint8_t i=0; 
  for (i=0; i<4; i++) { 
    digits7Segments[i] = 0; 
  } 
} 

void Afficheur7Seg::writeBitsToSend(uint8_t indexNumber, uint8_t digit) {
  if(indexNumber <=9)
  digits7Segments[indexNumber] = numbers[digit];
}



void Afficheur7Seg::displayScore(int score) {
  int i=3;
    do {
        int mod = score% 10;
        writeBitsToSend(i,mod);
        score = score / 10;
      i--;
    } while(score > 0 && i>=0);
    writeRegisters();
}
