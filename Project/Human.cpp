#include "Human.h"

Human::Human(std::string name) {
    this->name = std::move(name);
}

std::string Human::getName() {
    return this->name;
}

void Human::move(std::vector<int> &player1Cars, std::vector<int> &player2Cars) {
    takeUserCarToMove(player1Cars, player2Cars);
}

std::pair<int, int> Human::checkValidCells(int car1Position, std::vector<int> &player1Cars, std::vector<int> &player2Cars) {
    int nextMove = player1Cars[car1Position - 1];
//    if(nextMove >= player2Cars.size()) return {0, 0};
    std::pair<int,int> move = {0,0};
    if(nextMove <= player2Cars.size() && player2Cars[nextMove] != car1Position) move.first = 1;
    if(nextMove + 1 <= player2Cars.size() && player2Cars[nextMove + 1] != car1Position) move.second = 1;
//    if(player2Cars[nextMove] == car1Position){
//        return {0, 0};
//    }else if (nextMove + 1 == player2Cars.size() || player2Cars[nextMove + 1] == car1Position){
//        return {1, 0};
//    }else{
//        return {1, 1};
//    }
    return move;
}

void Human::takeUserCarToMove(std::vector<int> &player1Cars, std::vector<int> &player2Cars) {
    int car1Position;
    std::cout << "Choose car to move: ";
    std::cin >> car1Position;
    while (car1Position < 1 || car1Position > player1Cars.size()){
        std::cout << "Enter correct car number to move: ";
        std::cin >> car1Position;
    }
    std::pair<int, int> validCells = checkValidCells(car1Position, player1Cars, player2Cars);
    if(validCells.first == 0 && validCells.second == 0){
        std::cout << "Your chosen cell cannot be moved!\n";
        takeUserCarToMove(player1Cars, player2Cars);
    }
//    int validStepsToMove = 0;
    if(validCells.first == 1){
        player1Cars[car1Position - 1] += 1;
//        validStepsToMove = 1;
        std::cout << "Your car are moved 1 step forward\n";
    }else if(validCells.second == 1){
        player1Cars[car1Position - 1] += 2;
//        validStepsToMove = 2;
        std::cout << "Your car are moved 2 steps forward\n";
    }
//    int userStepsToMove;
//    std::cout << "Enter the number of steps to move your car: ";
//    std::cin >> userStepsToMove;
//    while (userStepsToMove < 1 || userStepsToMove > validStepsToMove){
//        std::cout << "Enter valid number to move: ";
//        std::cin >> userStepsToMove;
//    }
//    player1Cars[car1Position - 1] += userStepsToMove;
}
