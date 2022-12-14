# First Reach Game

 * There are two mode in this game
   * First one, human player vs computer player
   * Second one, human player vs another human player
 
 ## About this game
 
 ```
   > This game consists of n*n grid
   > each player can have (n-2) cars on the top row or on the left column
   > The goal from this game is to reach the other side firstly
        (if your car in the top row, your goal is to make all your cars in the down row)
        (if your car in the left column, your goal is to make all your cars in the right column)
   > The only valid move is to inly one step forward
        if the next cell isn't occupied, then you can move to it automatically
        if the next cell is occupied, you can move to the next next cell if it isn't occupied automatically
        if the next cell is occupied and the next next cell also is occupied, then you cannot move this car
 ```
 ## Diagram showing how to play this game
<p align="center">
 <img src="https://user-images.githubusercontent.com/101745968/207545746-18019676-dc1e-4a96-9c1f-49e296e8e748.png">
</p>

## The algorithm to determine the best move each car (if you play with computer)
> Using minmax algorithm, can determine the best move for each car

![image](https://user-images.githubusercontent.com/101745968/207545767-1e75359f-32c4-43d4-ac4e-33032e1c34ee.png)

## Screenshots
> When playing with the computer

![image](https://user-images.githubusercontent.com/101745968/207548408-fbb4610c-7e56-4868-a4d7-bccb5d1d91ef.png)

![image](https://user-images.githubusercontent.com/101745968/207548442-951afea4-4abe-4d43-a997-fd1c36b0894b.png)

![image](https://user-images.githubusercontent.com/101745968/207548483-f3a32cb3-1436-4ae3-bd50-fcb9fc906405.png)

![image](https://user-images.githubusercontent.com/101745968/207548520-359da3a3-4a86-42f8-9b13-9628ddb64b51.png)

> When playing with another human player

![image](https://user-images.githubusercontent.com/101745968/207549331-e03a0c75-617a-474a-9fd9-d0d3c2f0fe9e.png)

![image](https://user-images.githubusercontent.com/101745968/207549363-26ffaa23-2b02-47aa-9f5f-c56bed652926.png)

![image](https://user-images.githubusercontent.com/101745968/207549407-4b1048a8-edb6-4f99-9a2c-80de91fc7b3b.png)

![image](https://user-images.githubusercontent.com/101745968/207549447-03938459-24cd-4756-822d-99b0ff9de10f.png)


