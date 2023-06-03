#include <string>
using namespace std;

//powers class
class Power
{

    int id;//id of the power
    std::string description;//description of power
    int strength;//how much strength this power has
    int pp;//how many uses the power has, power points
    int effect;//effect on surrounding: 0 is damage enemy(default), 1 is protecting, 2 is healing.
    
    public:

    //constructor
    Power(int idnum, std::string desc,int str, int powpoi, int eff = 0)
    {
        id = idnum;
        description = desc;
        strength = str;
        pp = powpoi;
        effect = eff;
    }
    //get id
    int getId(){
        return id;
    }
    //sets new Id, can be used if two powers have the same Id
    void setId(int newId){
        id = newId;
        return;
    }
    //get description
    std::string getDesc(){
        return description;
    }
    //get strength
    int getStrength(){
        return strength;
    }
    //set strength
    void setStrength(int newStr){
        strength = newStr;
    }
    //get pp
    int getPp(){
        return pp;
    }
    //set pp
    void setPp(int newPp){
        pp = newPp;
    }
    //get effect
    int getEffect(){
        return effect;
    }
  
};

