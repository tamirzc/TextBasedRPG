#include <string>
using namespace std;

//Room class, defines the rooms of the map

class Room{

    int id;//id number of the room
    int northid;//id of room to north. -1 if wall
    int eastid;//id of room to east. -1 if wall
    int southid;//id of room to south. -1 if wall
    int westid;//id of room to west. -1 if wall

    std::string description;//description in the entrance to the room

    public:
    //constructor
    Room(int idNum, int north, int east, int south, int west, std::string desc){
        id = idNum;
        northid = north;
        eastid = east;
        southid = south;
        westid = west;
        description = desc;
    }
    //get id
    int getId(){
        return id;
    }
    //get nextRooms
    int getNorth(){
        return northid;
    }
    int getEast(){
        return eastid;
    }
    int getSouth(){
        return southid;
    }
    int getWest(){
        return westid;
    }
    //get description
    std::string getDesc(){
        return description;
    }
};