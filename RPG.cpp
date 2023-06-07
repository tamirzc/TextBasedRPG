#include <iostream>
#include <string>
#include "Indiv.h"

using namespace std;

bool fight(Indiv player, Indiv monster){
    return true;
}

char goNext(Indiv player){
    int w,e,n,s;//directions available to travel: is west/east/north/south available at the current location?
    char inputDir;//direction decided by the user
    Room* current = player.getLocation();
    
    w = current->getWest();
    e = current->getEast();
    n = current->getNorth();
    s = current->getSouth();

    cout << "\nWhich direction will you discover next?\n";

    if(w != -1){
        cout << "For west,press w.\n";
    }
    if(e != -1){
        cout << "For east,press e.\n";
    }
    if(n != -1){
        cout << "For north,press n.\n";
    }
    if(s != -1){
        cout << "For south,press s.\n";
    }

    cin >> inputDir;

    if(w != -1 && inputDir == 'w'){
        return 'w';
    }
    else if(e != -1 && inputDir == 'e'){
        return 'e';
    }
    else if(n != -1  && inputDir == 'n'){
        return 'n';
    }
    else if(s != -1  && inputDir == 's'){
        return 's';
    }
    else{
        return 'j'; //error sign, the player will be hurt.
    }
}

Indiv* checkEnemies(Indiv player, Indiv* enemies, int numOfEn){
    int currEnLoc, roomId;
    //get roomId
    roomId = player.getLocation()->getId();
    //go through enemy array, check which one is in room roomId
    for(int i=0;i<numOfEn;i++){
        currEnLoc = (*(enemies+i)).getLocation()->getId();
        if(currEnLoc == roomId){
            return (enemies+i);
        }
    }
    return NULL;
}

int main() {
    //declare and initialize variables
    bool gameOn = true; //finish the game or not
    int inputFromUser; //input in main menu
    char dir; //choose direction to go: w,e,n,s
    int dirId; //the id of next room

    //strings
    string dontFollowOrder = "You didn't follow my orders. Hence, you die, you body shredded into million tiny pieces in an agonizing pain. Goodbye.";

    string startString = "You enter the grim castle. The fog invades the interior, covering the room.\nYou squint, breathing in the cold, foggy air. Today, your mission will finally be complete, and you will finally free yourself from the curse, or die trying.\nAll is left to do is to kill the horrendous witch, waiting for you in her creepy castle.\n";

    string swordOfTheFallenString = "A sword, drenched in the blood of all that it killed in the past. If you listen carefully, you will hear their scream.";

    string fireballString = "a fireball comes out of your hand and scorches the enemy.";

    string room0String = "As you enter the room, a scream pierces the silence, freezing your blood. There is no turning back. You look at the vast room, your eyes getting accostumed to the darkness inside. As you look around, you spot a small item, laying in the back of the room, giving a dull shine. Pacing back and forth, a huge black creature. Stretching its four legs as he goes, the fur on his back shimmers, his big fangs shine like two crescent moons. In his red gleaming eyes, you see death. WWYD?\n1. Leave as you came, this things are not for you. \n2. Try to sneak behind and get the item.\n3. Take the little b1tch head on.\n4. Leave the room to the west, and take the stairs to the basement.";
    string room1String = "You are in room 1";
    string room2String = "You are in room 2";
    string room3String = "You are in room 3";
    string room4String = "You are in room 4";


    string loseString = "You leave the castle, defeated. As you put your leg out of the castle door, you hear whispers. They start as murmurs, lurking inside your ears. You wait for them to stop, but they just get louder. And louder. Their sinister meaning evading you, but you know they mean you ill. As the first ray of sunshine pierces the fog at the door, the mumur gets so loud, you kneel in their power. You close your ears, hopping they would go, but they just pierce your ears and brain, unrelenting. The curse slowly start boiling inside of you, filling you with dark, black fog, as the chanting pierces your brain. In your last breath, you understand you made a mistake coming here.";

    //items
    Item swordOfTheFallen(0,swordOfTheFallenString,5,0);

    //powers
    Power fireball(0,fireballString,20,3,0);
    //map
    Room room0(0,-1,-1,-1,1,room0String);//start room, bedroom
    Room room1(1,4,3,0,2,room1String);//main hall
    Room room2(2,-1,1,-1,-1,room2String);//play room
    Room room3(3,-1,-1,-1,1,room3String);//kitchen
    Room room4(4,-1,-1,1,-1,room4String);//end room, livingroom
    Room Castle[5]={room0,room1,room2,room3,room4};


    //Enemies
    Indiv shadowDog("The Shadow Dog",30,20,10,&room0);//dog
    Indiv horrorKid("The Small Horror",50,10,20,&room2);//bro
    Indiv bloatWoman("The Bloating Gore",120,5,40,&room3);//mom
    Indiv witch("The Witch",170,30,20,&room4);//dad
    Indiv enemies[4]={shadowDog,horrorKid,bloatWoman,witch};
    Indiv* currEn;



    //player
    Indiv player("Player",100,10,10,&room0);
    player.setPower(fireball);

    cout << startString;
    cout << room0.getDesc() << "\n";

    while (gameOn){
        currEn = checkEnemies(player,enemies,4);
        cin >> inputFromUser;
        switch (inputFromUser){
            case 1:
                cout << loseString;
                gameOn = false;
                break;
            case 2:
            //check randomly if successful evading or not. If not, might add penalty of damage, and fight function.
            //if taking the item, check if full, maybe replace item
                break;
            case 3:
            //fight function, in there option to use item to heal, use power or attack (besides healing,everything is with rand)
                break;
            case 4:
            //if the monster not dead, express that in string, and change chance to fight if back to 100%. also add chance to fail.
                if(currEn->getAlive()){
                    break;//change according to above comment
                }
                dir = goNext(player);
                switch(dir){
                    case 'w':
                        dirId = player.getLocation()->getWest();
                        break;
                    case 'e':
                        dirId = player.getLocation()->getEast();
                        break;
                    case 'n':
                        dirId = player.getLocation()->getNorth();
                        break;
                    case 's':
                        dirId = player.getLocation()->getSouth();
                        break;
                    default:
                        cout << dontFollowOrder;
                        gameOn = false;
                }
                if(gameOn){
                    player.setLocation(&Castle[dirId]);
                    cout << player.getLocation()->getDesc();
                }
                break;
            default:
                cout << dontFollowOrder;
                gameOn = false;
                break;
        }
    }




    return 0;
}