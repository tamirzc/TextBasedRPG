#include <iostream>
#include <string>
#include "Indiv.h"


using namespace std;

int main() {
    //declare and initialize variables
    bool gameOn = true;
    int inputFromUser;

    //strings
    string dontFollowOrder = "You didn't follow my orders. Hence, you die, you body shredded into million tiny pieces in an agonizing pain. Goodbye.";

    string startString = "You enter the grim castle. The fog invades the interior, covering the room.\nYou squint, breathing in the cold, foggy air. Today, your mission will finally be complete, and you will finally free yourself from the curse, or die trying.\nAll is left to do is to kill the horrendous witch, waiting for you in her creepy castle.\n";

    string swordOfTheFallenString = "A sword, drenched in the blood of all that it killed in the past. If you listen carefully, you will hear their scream.";

    string fireballString = "a fireball comes out of your hand and scorches the enemy.";

    string room0String = "As you enter the room, a scream pierces the silence, freezing your blood. There is no turning back. You look at the vast room, your eyes getting accostumed to the darkness inside. As you look around, you spot a small item, laying in the back of the room, giving a dull shine. Pacing back and forth, a huge black creature. Stretching it four legs as he goes, the fur on his back shimmers, his big fangs shine like two crescent moons. In his red gleaming eyes, you see death. WWYD?\n1. Leave as you came, this things are not for you. \n2. Try to sneak behind and get the item.\n3. Take the little b1tch head on.\n4. Leave the room to the west, and take the stairs to the basement.";

    string loseString = "You leave the castle, defeated. As you put your leg out of the castle door, you hear whispers. They start as murmurs, lurking inside your ears. You wait for them to stop, but they just get louder. And louder. Their sinister meaning evading you, but you know they mean you ill. As the first ray of sunshine pierces the fog at the door, the mumur gets so loud, you kneel in their power. You close your ears, hopping they would go, but they just pierce your ears and brain, unrelenting. The curse slowly start boiling inside of you, filling you with dark, black fog, as the chanting pierces your brain. In your last breath, you understand you made a mistake coming here.";

    //items
    Item swordOfTheFallen(0,swordOfTheFallenString,5,0);

    //powers
    Power fireball(0,fireballString,20,3,0);
    //map
    Room room0(0,-1,-1,-1,1,room0String);

    //player
    Indiv player("Player",100,10,10,&room0);
    player.setPower(fireball);

    Item* items;
    Power* powers;
    cout << startString;
    cout << room0.getDesc() << "\n";

    while (gameOn){
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
            //if the monster not dead, express that in string, and change chance to fight if back to 100%
                break;
            default:
                cout << dontFollowOrder;
                gameOn = false;
                break;
        }
    }




    return 0;
}