#include <string>
#include "powers.h"
#include "items.h"
#include "map.h"


Power defPower(-1,"NULL",-1,-1,-1);
Item defItem(-1,"NULL",-1,-1);
Room defRoom(-1,-1,-1,-1,-1,"NULL");

//Indiv class, from individual - a class of every character
class Indiv
{
    std::string name;//name
    int HP;//Health point
    Item items[3] = {defItem,defItem,defItem};//list of items held
    Power powers[2] = {defPower,defPower};//list of powers of the Indiv
    int STR;//strength of Indiv
    int DEF;//defence of Indiv
    Room location = defRoom;//location in the map
    bool alive = true;
    
    public:

    //constructor
    Indiv(std::string nam, int health, int strength, int defence, Room* locate)
    {
        name = nam;
        HP = health;
        STR = strength;
        DEF = defence;
        location = *locate;
    }
    
    //gets the name of the individual
    std::string getName(){
        return name;
    }
    //set alive status
    void setAlive(bool status){
        alive = status; //true for alive, false for dead
        return;
    }
    //get alive status
    bool getAlive(){
        return alive;
    }    
    //set HP to a new value
    void setHP(int newHPVal){
        HP = newHPVal;
        return;
    }
    //get the value of HP
    int getHP(){
        return HP;
    }
    //calculate damage in battle, and returns 1 if the Indiv died.
    void setDamagetoHP(int damage){
        setHP(HP - damage);
        if(HP <= 0){
            setAlive(false);
        }
        return;
    }
    //set STR to a new value
    void setSTR(int newSTRVal){
        STR = newSTRVal;
        return;
    }
    //get the value of STR
    int getSTR(){
        return STR;
    }
    //set DEF to a new value
    void setDEF(int newDEFVal){
        DEF = newDEFVal;
        return;
    }
    //get the value of DEF
    int getDEF(){
        return DEF;
    }
    //change location of Indiv, send 1 if tries to go to a wrong place
    void setLocation(Room *newLoc){
        location = *newLoc;
        return;
    }    
    //get the location of the Indiv
    Room* getLocation(){
        return &location;
    }
    //check if bag is full, if not add item
    bool setItem(Item newItem){
        bool isInserted = false; //check if the new item was inserted
        for(int i=0; i<=2; i++){
            if(items[i].getId() == -1){
                items[i]=newItem;
                if(items[i].getEffect() == 0){
                    setSTR(STR+items[i].getStrength());
                }
                else if(items[i].getEffect() == 1){
                    setDEF(DEF+items[i].getStrength());
                }
                isInserted = true; //item was inserted
                break;
            }
        }
        if(isInserted == true){
            return true;//insertion is Ok
        }
        else{
            return false;//items are full
        }

    }
    //get items array
    Item* getItems(){
        return items;
    }
    //check if have all powers, if not add one
    bool setPower(Power newPower){
        int idnum;
        bool isInserted = false; //check if the new power was inserted
        for(int i=0; i<=1;i++){
            idnum = powers[i].getId();
            if(idnum == -1){
                powers[i]=newPower;
                isInserted = true;
                break;
            }
        }
        if(isInserted == true){
            return true;//insertion is Ok
        }
        else{
            return false;//items are full
        }
    }
    //get items array
    Power* getPower(){
        return powers;
    }
  
};
