#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <numeric>
class GameWorld
{
    public:
        GameWorld();
        virtual ~GameWorld();

        void initializeWorld();
        int generateRandomNm();
        void printWorld();
        int earnPointOfField(int x, int y, int z);
        int sortAndDigPoints(int x, int y);
        int sortAndFindAvgPoints(int x, int y);
        void mixWorld();

        std::vector<std::vector<std::vector<int>>> GetWorld(){return vector3d;}
    protected:

    private:

    std::vector<std::vector<std::vector<int>>> vector3d;
};

#endif // GAMEWORLD_H
