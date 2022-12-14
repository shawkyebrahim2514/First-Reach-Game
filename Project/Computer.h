#ifndef FIRST_REACH_GAME_COMPUTER_H
#define FIRST_REACH_GAME_COMPUTER_H
#include "Player.h"

class Computer : public Player{
    int findBestMove(std::vector<int> player1Cars, std::vector<int> player2Cars, bool isMaximizing);
public:
    explicit Computer(std::string name);
    void move(std::vector<int>& player1Cars, std::vector<int>& player2Cars) override;
    std::string getName() override;
};


#endif