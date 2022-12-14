#include "FirstReachGame.h"

FirstReachGame::FirstReachGame() {
    this->cars.resize(2);
}

FirstReachGame::~FirstReachGame() {
    delete this->players[0];
    delete this->players[1];
}

void FirstReachGame::run() {
    takeGridSize();
    takeGameMode();
    showGameGrid();
    separateLine("");
    bool isPlayer2Turn = false;
    int gameRound = 0;
    while (!checkWinner()){
        if(gameRound != 0 && gameRound%2) separateLine("");
        std::cout << players[isPlayer2Turn]->getName() << " turn\n";
        players[isPlayer2Turn]->move(this->cars[isPlayer2Turn], this->cars[!isPlayer2Turn]);
        showGameGrid();
        isPlayer2Turn = !isPlayer2Turn;
        gameRound ++;
    }
}

void FirstReachGame::takeGridSize() {
    std::cout << "Enter the size of the game grid: ";
    std::cin >> gameGridSize;
    while (gameGridSize <= 2){
        std::cout << "Please enter size that is greater than 2: ";
        std::cin >> gameGridSize;
    }
    cars[0].resize(gameGridSize - 2, 0);
    cars[1].resize(gameGridSize - 2, 0);
}

bool FirstReachGame::checkWinner() {
    int cars1Winners = 0, cars2Winners = 0;
    for(auto& carPosition : cars[0]){
        if(carPosition == gameGridSize - 1) cars1Winners ++;
    }
    for(auto& carPosition : cars[1]){
        if(carPosition == gameGridSize - 1) cars2Winners ++;
    }
    if(cars1Winners == gameGridSize - 2 && cars2Winners == gameGridSize - 2){
        std::cout << "Tie!\n";
        return true;
    }else if(cars1Winners == gameGridSize - 2){
        std::cout << players[0]->getName() << " is the winner!\n";
        return true;
    }else if(cars2Winners == gameGridSize - 2){
        std::cout << players[1]->getName() << " is the winner!\n";
        return true;
    }
    return false;
}

void FirstReachGame::takeGameMode() {
    int mode;
    std::cout << "Do you want to play with computer or with another human player?\n";
    std::cout << "> Enter (1) if you want to play with computer.\n";
    std::cout << "> Enter (2) if you want to play with another human player.\n";
    std::cin >> mode;
    while (mode < 1 || mode > 2){
        std::cout << "Enter correct choice: ";
        std::cin >> mode;
    }
    if(mode == 1){
        // first player is the human
        // second player is the computer
        std::string humanName;
        std::cout << "Enter human player name: ";
        std::cin >> humanName;
        int direction;
        std::cout << "Do you want your car in top(1) or left(2)? ";
        std::cin >> direction;
        while (direction < 1 || direction > 2){
            std::cout << "Enter correct choice: ";
            std::cin >> direction;
        }
        if(direction == 1){
            players[0] = new Human(humanName);
            players[1] = new Computer("Computer");
        }else{
            players[0] = new Computer("Computer");
            players[1] = new Human(humanName);
        }
    }else{
        // first player is human 1
        // second player is human 2
        std::string humanName1, humanName2;
        std::cout << "Enter human player1 name(has top cars): ";
        std::cin >> humanName1;
        std::cout << "Enter human player2 name(has left cars): ";
        std::cin >> humanName2;
        players[0] = new Human(humanName1);
        players[1] = new Human(humanName2);
    }
}

void FirstReachGame::showGameGrid() {
    std::vector<std::vector<char>> gameGrid(gameGridSize,
                                                   std::vector<char>(gameGridSize , '.'));
    for (int i = 0; i < gameGridSize - 2; ++i) {
        gameGrid[cars[0][i]][i+1] = 'v';
    }
    for (int i = 0; i < gameGridSize - 2; ++i) {
        gameGrid[i + 1][cars[1][i]] = '>';
    }
    for (int i = 0; i < gameGridSize; ++i) {
        for (int j = 0; j < gameGridSize; ++j) {
            std::cout << gameGrid[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void FirstReachGame::separateLine(const std::string &paragraph) {
    int width = 144;
    int part = width/2 - paragraph.size()/2;
    std::cout << std::string(part, '-') << paragraph << std::string(part, '-') << '\n';
}