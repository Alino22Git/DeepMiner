#ifndef AVERAGEBOT_H
#define AVERAGEBOT_H
#include "Bot.h"


class AverageBot : public Bot
{
    public:
        AverageBot(std::string name);
        virtual ~AverageBot();
        virtual void mineBlock(GameWorld* gw) override;

    protected:

    private:
};

#endif // AVERAGEBOT_H
