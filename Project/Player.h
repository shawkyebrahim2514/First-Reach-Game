#ifndef FIRST_REACH_GAME_PLAYER_H
#define FIRST_REACH_GAME_PLAYER_H
#include <vector>
#include <iostream>

class Player {
protected:
    std::string name;
public:
    Player(){};
    virtual void move(std::vector<int>& player1Cars, std::vector<int>& player2Cars) = 0;
    virtual std::string getName() = 0;
     virtual ~Player(){};
};


#endif
