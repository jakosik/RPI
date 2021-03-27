#include <cstdint> 
#include <wiringPi.h> 
#include <wiringPiI2C.h> 
#include <vector>
static const uint8_t nombres[] = { 
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
      void eteindre();
      void ecrireRegistres();
      void clear();
      void ecrireBitsAEnvoyer(uint8_t indexNumero, uint8_t chiffre);
      void entrerScore(int score);
      void getNumberList(int score);

    private:
      uint16_t chiffres7Segments[4];
      int fileDesc;    
      vector<int> listeNombresAfficher; 
};