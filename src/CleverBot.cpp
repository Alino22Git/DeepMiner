#include "../include/CleverBot.h"

CleverBot::CleverBot(std::string name)
{
   this->name = name;
}

CleverBot::~CleverBot()
{
    //dtor
}

void CleverBot::mineBlock(GameWorld* gw){
std::cout<<"Using CPU to find the best digging Spot!"<<std::endl;
points+=gw->sortAndDigPoints(x_coordinate,y_coordinate);
 }
