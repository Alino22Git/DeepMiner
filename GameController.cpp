#include "include/GameController.h"

Bot* selectBot(std::string name,int cpu) {
    int num=0;
    if(cpu==1) {
        num=rand()%3;
    } else {
        do {
            std::cout<<"Which Bot do you pick?\nCleverBot(0)     DeepBot(1)     AverageBot(2)"<<std::endl;
            std::cin>>num;
            system("cls");
            if(num!=2&&num!=1&&num!=0) {
                system("cls");
                std::cout<<"This is not an option!\nTry again!"<<std::endl;
            }
        } while(num!=2&&num!=1&&num!=0);
    }
    if(num==2) {
        return new AverageBot(name);
    } else if(num==0) {
        return new CleverBot(name);
    } else if(num==1) {
        return new DeepBot(name);
    }
    return nullptr;
}

void prepareGame() {
    srand(time(NULL));
    Bot* choosenBot = selectBot(chooseName(),0);
    Bot* CPUBot = selectBot("Bot",1);
    startGame(choosenBot,CPUBot);
}

std::string chooseName() {
    std::string name = " ";
    std::cout<<"Enter a Nickname: ";
    std::cin>>name;

    return name;
}

void startGame(Bot* player, Bot* cpu) {
//    std::vector<std::vector<std::vector<int>>> levels;
    GameWorld* gw = new GameWorld();
    gw->initializeWorld();
    do {

        direction(player,0);
        if(check(player,gw)) {
            player->mineBlock(gw);
        }
            std::cout<<"---------------"<<std::endl;
//        gw->printWorld();
        direction(cpu,1);
        if(check(cpu,gw)) {
            cpu->mineBlock(gw);
        }
        std::cout<<"---------------"<<std::endl;
//        cpu->mineBlock(gw);
        if(player->Getpoints()%50==0 ||cpu->Getpoints()%50==0 ) {
//        system("cls");
//        gw->printWorld();
            gw->mixWorld();
//    std::cout<<"-------------\n";
//gw->printWorld();
        }

    } while(player->Getpoints()<300 && cpu->Getpoints()<300);
    system("cls");
    if(player->Getpoints()>=300) {
        won(player);
    } else {
        won(cpu);
    }
}
bool check(Bot* bot, GameWorld* gw) {

    std::vector<std::vector<std::vector<int>>> fields=gw->GetWorld();
    for(int i=0; i<10; i++) {
        if(fields[bot->GetCoordinateX()][bot->GetCoordinateY()][i]==-2) {
            gw->earnPointOfField(bot->GetCoordinateX(),bot->GetCoordinateY(),i);
            searchBadMiningSpot(bot,gw);
            std::cout<<"Your drill got stuck!\nAnd you slipped in a hole."<<std::endl;
            return false;
        }

        if(fields[bot->GetCoordinateX()][bot->GetCoordinateY()][i]==-1) {
            gw->earnPointOfField(bot->GetCoordinateX(),bot->GetCoordinateY(),i);
            std::cout<<"Your drill got stuck!"<<std::endl;

            return false;
        }
    }
    return true;
}

void searchBadMiningSpot(Bot* bot,GameWorld* gw) {
    std::vector<std::vector<std::vector<int>>> fields=gw->GetWorld();
    int times=0;
    do {
        for(int x=0; x<5; x++) {
            for(int y=0; y<5; y++) {
                if(fields[x][y][9]==times) {
                    bot->moveBot(x,y);
                }
            }
        }
        times++;
    } while(times==5);
}

void direction(Bot* bot,int cpu) {
    using namespace std;
    char dir=' ';
    int accepted=1;
    if(cpu==1)
        info(bot);
    do {

    if(cpu==0){
        info(bot);
        cout<<"Which direction you wanna mine?\nforward(w)  back(s)  left(s)  right(d)  stay(x)"<<endl<<":";
        cin>>dir;
        system("cls");
        cin.clear();
        cin.ignore(2, '\n');
    }else{
    dir=cpuDecision();
    }
        switch(dir) {
        case 'x':
            accepted=0;
            break;
        case 'w':
            if(bot->GetCoordinateY()!=4) {
                bot->decreaseY(1);
                accepted=0;
            } else {
                if(cpu==0)
                cout<<"You cannot move in this direction!\nTry again."<<endl;
            }
            break;
        case 'a':
            if(bot->GetCoordinateX()!=0) {
                bot->decreaseX(-1);
                accepted=0;
            } else {
                if(cpu==0)
                cout<<"You cannot move in this direction!\nTry again."<<endl;
            }
            break;
        case 's':
            if(bot->GetCoordinateY()!=0) {
                bot->decreaseY(-1);
                accepted=0;
            } else {
                if(cpu==0)
                cout<<"You cannot move in this direction!\nTry again."<<endl;
            }
            break;
        case 'd':
            if(bot->GetCoordinateX()!=4) {
                bot->decreaseX(1);
                accepted=0;
            } else {
                if(cpu==0)
                cout<<"You cannot move in this direction!\nTry again."<<endl;
            }
            break;
        default:
            if(cpu==0)
            cout<<"Try Again!"<<endl;
            break;
        }
    } while(accepted);

}

void info(Bot* bot) {
    using namespace std;
    cout<<"Turn of: "<<bot->Getname()<<endl;
    cout<<"Points: "<<bot->Getpoints()<<endl;
    cout<<"X-Coordinate: "<<bot->GetCoordinateX()<<" / Y-Coordinate: "<<bot->GetCoordinateY()<<endl;
}

void won(Bot* bot) {
    using namespace std;
    cout<<"Congratulations!"<<endl;
    cout<<"The Player "<<bot->Getname()<<" won the game with "<<bot->Getpoints()<<" points!"<<endl;
}

char cpuDecision() {
    int decision=rand()%5;
    if(decision==4) {
        return 'w';
    }
    if(decision==3) {
        return 'a';
    }
    if(decision==2) {
        return 's';
    }
    if(decision==1) {
        return 'd';
    }else{
        return 'x';
    }

}
