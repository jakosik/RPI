#include <iostream>
using namespace std;
class Snake {
    public:
        Snake();
        void fillWalls();
        void defineStartPosition();
    private:
        char level [40][40];
};


