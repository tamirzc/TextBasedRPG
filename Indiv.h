#include <string>
#include "powers.h"

Power defPower(-1,"NULL",-1,-1,-1);

//Indiv class, from individual - a class of every character
class Indiv
{
    std::string name;//name
    int HP;//Health point
    int items[3] = {0,0,0};//list of items held
    Power powers[2] = {defPower,defPower};//list of powers of the Indiv
    int STR;//strength of Indiv
    int DEF;//defence of Indiv
    int location;//location in the map
    
    public:

    //constructor
    Indiv(std::string nam, int health, int strength, int defence, int locate)
    {
        name = nam;
        HP = health;
        STR = strength;
        DEF = defence;
        location = locate;
    }
    
    //gets the name of the individual
    std::string getName(){
        return name;
    }
    //check if bag is full, if not add item
    int setItems(int newItem){
        for(int i : items){
            if(items[i] != 0){
                items[i]=newItem;
                break;
            }
            else {
                return -1;
            }
            return 0;
        }
    }
    //get items array
    int* getItems(){
        return items;
    }
    //check if have all powers, if not add one
    void setPower(Power newPower){
        for(int i=0; i<=1;i++){
            int idnum = powers[i].getId();
            if(idnum == -1){
                powers[i]=newPower;
                break;
            }
            return;
        }
    }
    //get items array
    Power* getPower(){
        return powers;
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
    int setDamagetoHP(int damage){
        setHP(HP - damage);
        if(HP <= 0){
            return -1;
        }
        return 0;
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
    int setLocation(int newLoc){
        location = newLoc;
        //check need to be done when map is made!
        return 0;
    }    
    //get the location of the Indiv
    int getLocation(){
        return location;
    }
  
};
