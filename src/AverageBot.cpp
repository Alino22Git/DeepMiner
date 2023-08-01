#include "../include/AverageBot.h"

AverageBot::AverageBot(std::string name)
{
   this->name = name;
}

AverageBot::~AverageBot()
{
    //dtor
}

void AverageBot::mineBlock(GameWorld* gw){
std::cout<<"Just takes the average Spots!";
points+=gw->sortAndFindAvgPoints(x_coordinate,y_coordinate);
 }
