#ifndef CLEVERBOT_H
#define CLEVERBOT_H
#include "Bot.h"


class CleverBot : public Bot
{
    public:
        CleverBot(std::string name);
        virtual ~CleverBot();
        virtual void mineBlock(GameWorld* gw) override;

    protected:

    private:
};

#endif // CLEVERBOT_H
