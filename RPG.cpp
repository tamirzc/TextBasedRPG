#include <iostream>
#include <string>
#include "Indiv.h"
#include "map.h"
#include "items.h"


using namespace std;

int main() {
    
    Indiv player("Player",100,10,10,0);
    Power fireball(0,"a fireball comes out of your hand and scorches the enemy.",20,3,0);
    Room gameMap(0,-1,-1,-1,-1,"clunky");
    Item swordOfTruth(0,"a sword that speaks the truth",5,0);

    player.setPower(fireball);

    cout << player.getPower()[0].getDesc();

    return 0;
}