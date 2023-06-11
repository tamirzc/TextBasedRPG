#include <string>
using namespace std;

//items class
class Item
{

    int id;//id of the item
    std::string description;//description of item
    int strength;//how much the item adds to power/protects/heals
    int effect;//effect on surrounding: 0 is adding to damage(default), 1 is adding to protection, 2 is healing.
    bool taken = false;//check if item was taken or not
    
    public:

    //constructor
    Item(int idnum, std::string desc,int str, int eff = 0)
    {
        id = idnum;
        description = desc;
        strength = str;
        effect = eff;
    }
    //get id
    int getId(){
        return id;
    }
    //get description
    std::string getDesc(){
        return description;
    }
    //get strength
    int getStrength(){
        return strength;
    }
    //get effect
    int getEffect(){
        return effect;
    }
    //get taken
    bool getTaken(){
        return taken;
    }
    //set taken
    void setTaken(bool state){
        taken = state;
        return;
    }
};

