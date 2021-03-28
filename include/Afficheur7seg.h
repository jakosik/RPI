#include <cstdint> 
#include <wiringPi.h> 
#include <wiringPiI2C.h> 
#include <vector>
static const uint8_t numbers[] = { 
	0x3F, /* 0 (abcdef)*/ 
	0x06, /* 1 (bc)*/ 
	0x5B, /* 2 (abged)*/ 
	0x4F, /* 3 (abgcd)*/ 
	0x66, /* 4 (fgbc)*/ 
	0x6D, /* 5 (afgcd)*/ 
	0x7D, /* 6 (afgcde)*/ 
	0x07, /* 7 (abc)*/ 
	0x7F, /* 8 (abcdef)*/ 
	0x6F, /* 9 (fabgcd)*/
  /**********
  *    _ a
  * f | | b
  *    _ g
  *  e| |  c 
  *    _ d
  *****************/
}; 

using namespace std;
class Afficheur7Seg {
  

    public:
      Afficheur7Seg();
      void shutdown();
      void displayScore(int score);


    private:

      void writeRegisters();
      void clear();
      void writeBitsToSend(uint8_t indexNumero, uint8_t chiffre);
      void getNumberList(int score);
      uint16_t digits7Segments[4];
      int fileDesc;     
};