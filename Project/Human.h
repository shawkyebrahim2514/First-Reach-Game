#ifndef FIRST_REACH_GAME_HUMAN_H
#define FIRST_REACH_GAME_HUMAN_H
#include "Player.h"

class Human : public Player{
    std::pair<int, int> checkValidCells(int car1Position, std::vector<int> &player1Cars, std::vector<int> &player2Cars);
    void takeUserCarToMove(std::vector<int> &player1Cars, std::vector<int> &player2Cars);
public:
    explicit Human(std::string name);
    void move(std::vector<int>& player1Cars, std::vector<int>& player2Cars) override;
    std::string getName() override;
};


#endif