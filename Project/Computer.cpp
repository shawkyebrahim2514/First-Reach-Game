#include "Computer.h"

Computer::Computer(std::string name) {
    this->name = name;
}

std::string Computer::getName() {
    return this->name;
}

void Computer::move(std::vector<int> &player1Cars, std::vector<int> &player2Cars) {
    int bestScore = -100000;
    int pickedCar = 0;
    int numberOfMoves = 0;
    for (int i = 0; i < player1Cars.size(); ++i) {
        int nextMove = player1Cars[i];
        if(nextMove <= player2Cars.size() && player2Cars[nextMove] != i + 1){
            player1Cars[i] += 1;
            int score = findBestMove( player1Cars, player2Cars, false);
            if (score > bestScore) {
                bestScore = score;
                pickedCar = i;
                numberOfMoves = 1;
            }
            player1Cars[i] -= 1;
        }else if(nextMove + 1 <= player2Cars.size() && player2Cars[nextMove + 1] != i + 1){
            player1Cars[i] += 2;
            int score = findBestMove( player1Cars, player2Cars, false);
            if (score > bestScore) {
                bestScore = score;
                pickedCar = i;
                numberOfMoves = 2;
            }
            player1Cars[i] -= 2;
        }
    }
    player1Cars[pickedCar] += numberOfMoves;
    std::cout << "The computer moved car number " << pickedCar + 1 << '\n';
    std::cout << "This car are moved " << numberOfMoves << " steps forward\n";
}

int Computer::findBestMove(std::vector<int> player1Cars, std::vector<int> player2Cars, bool isMaximizing) {
    int cars1Winners = 0, cars2Winners = 0;
    for(auto& carPosition : player1Cars){
        if(carPosition == player1Cars.size() + 1) cars1Winners ++;
    }
    for(auto& carPosition : player2Cars){
        if(carPosition == player2Cars.size() + 1) cars2Winners ++;
    }
    if(cars1Winners == player1Cars.size() && cars2Winners == player2Cars.size()) return 0;
    if(cars1Winners == player1Cars.size()) return 100;
    if(cars2Winners == player2Cars.size()) return -100;
    if(isMaximizing){
        int score = -100000;
        for (int i = 0; i < player1Cars.size(); ++i) {
            int nextMove = player1Cars[i];
            if(nextMove <= player2Cars.size() && player2Cars[nextMove] != i + 1){
                player1Cars[i] += 1;
                score = std::max(score, findBestMove( player1Cars, player2Cars, false));
                player1Cars[i] -= 1;
            }else if(nextMove + 1 <= player2Cars.size() && player2Cars[nextMove + 1] != i + 1){
                player1Cars[i] += 2;
                score = std::max(score, findBestMove( player1Cars, player2Cars, false));
                player1Cars[i] -= 2;
            }
        }
        return score;
    }else{
        int score = 100000;
        for (int i = 0; i < player2Cars.size(); ++i) {
            int nextMove = player2Cars[i];
            if(nextMove <= player2Cars.size() && player2Cars[nextMove] != i + 1){
                player2Cars[i] += 1;
                score = std::min(score, findBestMove( player1Cars, player2Cars, true));
                player2Cars[i] -= 1;
            }else if(nextMove + 1 <= player2Cars.size() && player2Cars[nextMove + 1] != i + 1){
                player2Cars[i] += 2;
                score = std::min(score, findBestMove( player1Cars, player2Cars, true));
                player2Cars[i] -= 2;
            }
        }
        return score;
    }
}
