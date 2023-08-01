#ifndef GAMECONTROLLER_H_INCLUDED
#define GAMECONTROLLER_H_INCLUDED
#include <iostream>
#include <string>
#include <ctime>
#include "vector"
#include "Bot.h"
#include "GameWorld.h"
#include "CleverBot.h"
#include "AverageBot.h"
#include "DeepBot.h"


//Prototype
void prepareGame();
Bot* selectBot(std::string,int cpu);
std::string chooseName();
void startGame(Bot* player, Bot* cpu);
void direction(Bot* bot, int cpu);
void info(Bot* bot);
void won(Bot* bot);
bool check(Bot* bot, GameWorld* gw);
void searchBadMiningSpot(Bot* bot,GameWorld* gw);
char cpuDecision();
#endif // GAMECONTROLLER_H_INCLUDED
