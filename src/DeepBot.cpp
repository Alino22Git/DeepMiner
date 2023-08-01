#include "../include/DeepBot.h"

DeepBot::DeepBot(std::string name)
{
    this->name = name;
}

DeepBot::~DeepBot()
{
    //dtor
}

 void DeepBot::mineBlock(GameWorld* gw){
std::cout<<"The DeepBot drills 3 Blocks deep!\n";
points+=gw->earnPointOfField(x_coordinate,y_coordinate,9);
points+=gw->earnPointOfField(x_coordinate,y_coordinate,8);
points+=gw->earnPointOfField(x_coordinate,y_coordinate,7);
}
