#ifndef FIRST_REACH_GAME_FIRSTREACHGAME_H
#define FIRST_REACH_GAME_FIRSTREACHGAME_H
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include <vector>
#include <iostream>

class FirstReachGame {
    int gameGridSize;
    Player* players[2];
    std::vector<std::vector<int>> cars;
    void takeGridSize();
    bool checkWinner();
    void takeGameMode();
    void showGameGrid();
    void separateLine(const std::string& paragraph);
public:
    FirstReachGame();
    void run();
    ~FirstReachGame();
};

#endif