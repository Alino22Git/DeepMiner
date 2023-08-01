#include "../include/GameWorld.h"

GameWorld::GameWorld() {
    using namespace std;
    vector<vector<vector<int>>> vector3d(5, vector<vector<int>>(5, vector<int>(10, 0)));
}

GameWorld::~GameWorld() {
    //dtor
}

void GameWorld::initializeWorld() {
    using namespace std;
    int x=5, y=5, z=10;
    for(int i=0; i<x; i++) {
        vector<vector<int>> v2d;
        for(int j=0; j<y; j++) {
            vector<int> v1d;
            for(int k=0; k<z; k++) {
                v1d.push_back(generateRandomNm());
            }
            v2d.push_back(v1d);
        }
        vector3d.push_back(v2d);
    }
}

void GameWorld::printWorld() {
    using namespace std;
    int x=5, y=5, z=10;
    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            for(int k=0; k<z; k++) {
                cout<<vector3d[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

int GameWorld::generateRandomNm() {
    int num = rand()%9+1;
    if(num==1){
            if(rand()%10<1){
        return (rand()%2+1)*(-1);
            }
    }
    return num;
}

int GameWorld::earnPointOfField(int x, int y, int z) {
    int points=0;
    points=vector3d[x][y][z];
    vector3d[x][y][z]=0;
    return points;
}

int GameWorld::sortAndDigPoints(int x, int y) {
    std::vector<int> v{ vector3d[x][y][9], vector3d[x][y][8], vector3d[x][y][7], vector3d[x][y][6], vector3d[x][y][5], vector3d[x][y][4], vector3d[x][y][3], vector3d[x][y][2], vector3d[x][y][1], vector3d[x][y][0] };
    sort(v.begin(), v.end(), std::greater<int>());

    for(int z = 0; (unsigned) z<v.size(); z++) {
        if(vector3d[x][y][z]==v[0]) {
            return earnPointOfField(x,y,z);
        }
    }
    return 0;
}

int GameWorld::sortAndFindAvgPoints(int x, int y) {
    std::vector<int> v{ vector3d[x][y][9], vector3d[x][y][8], vector3d[x][y][7], vector3d[x][y][6], vector3d[x][y][5], vector3d[x][y][4], vector3d[x][y][3], vector3d[x][y][2], vector3d[x][y][1], vector3d[x][y][0] };
    int average = std::accumulate(v.begin(), v.end(), 0.0) / v.size();
    int points = 0;
    std::cout<<"The average of the layers is: "<<average<<std::endl;
    for(int z = 0; (unsigned) z<v.size(); z++) {
        if(vector3d[x][y][z]==average) {
            points+= earnPointOfField(x,y,z);
        }
    }
    return points;
}

void GameWorld::mixWorld() {
    int option = rand()%3;
    if(option==0) {
        //RANDOM SHUFFLE
        std::random_shuffle(vector3d.begin(), vector3d.end());
    } else if(option==2) {
        //SORT THE Z-VALUES ASCENDING
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                sort(vector3d[i][j].begin(), vector3d[i][j].end());
            }
        }

    } else {
        //SORT THE Z-VALUES ASCENDING
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                sort(vector3d[i][j].begin(), vector3d[i][j].end(),std::greater<int>());
            }
        }
    }
}


