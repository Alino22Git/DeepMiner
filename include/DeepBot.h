#ifndef DEEPBOT_H
#define DEEPBOT_H
#include "Bot.h"


class DeepBot : public Bot
{
    public:
        DeepBot(std::string name);
        virtual ~DeepBot();
        virtual void mineBlock(GameWorld* gw) override;

    protected:

    private:
};

#endif // DEEPBOT_H
