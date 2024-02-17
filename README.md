# Chess Code Sample
##### Author: William McCarty
##### 2024
----
### Description
----
This is a simple chess game ran using C++.  In the application you enter in two sets of codes, the piece you are wanting to move and the location you want to move it to.  The User plays as both Player 1 and Player 2.  If the player becomes in check from a move it will let the following player know.  Game will only end when the user types in `e`

The basic concept of chess is to move your pieces in a way to prevent their King from being able to move out of the way of being captured.  Each pieces has its own movements they can do to advance and capture the opponents pieces.

----
### Requirements
----
- C++

----
### Running Program
----

1. You can run the executable
`/Debug.Chess-Code-Sample.exe`

or

2. CMake the project and build, navigate to root directory of project and run in terminal.
`cmake .`
`cmake --build .`

3. Launch generated executable.

----
### Game Board
----


```
     C++ Chess
------------------
  a b c d e f g h
 *****************
8*R*H*B*Q*K*B*H*R*
 *****************
7*P*P*P*P*P*P*P*P*
 *****************
6* * * * * * * * *
 *****************
5* * * * * * * * *
 *****************
4* * * * * * * * *
 *****************
3* * * * * * * * *
 *****************
2*p*p*p*p*p*p*p*p*
 *****************
1*r*h*b*q*k*b*h*r*
 *****************
    Game Start
------------------
Player1=lowercase;Player2=uppercase
command template: FromPosition ToPosition
type 'e' to end the game
Player 1:
```
When the Application Starts it will look like the above.  This symbolizes the Game board.
The numbers on the left and the letters on the top of the board are the coordinates you use to select the piece you want to move and the destination you want that piece to end up at.

The pieces are the letters within the board area with letters, the letters are mapped to the type of piece they are and lowercase is Player1, uppercase is Player 2.
```
R = Rook - Player 2
H = Knight(horse) - Player 2
B = Bishop - Player 2
Q = Queen - Player 2
K = King = Player 2
P = Pawn = Player 2

r = Rook - Player 1
h = Knight(horse) - Player 1
b = Bishop - Player 1
q = Queen - Player 1
k = King = Player 1
p = Pawn = Player 1
```

----
### Movement
----
To move a piece you must specify the piece coordinate you are wanting to move followed by the destination.  so it follows the format
`[Letter on top][Number on left] [Letter on top][Number on left]`

So for example
```
     C++ Chess
------------------
  a b c d e f g h
 *****************
8*R*H*B*Q*K*B*H*R*
 *****************
7*P*P*P*P*P*P*P*P*
 *****************
6* * * * * * * * *
 *****************
5* * * * * * * * *
 *****************
4* * * * * * * * *
 *****************
3* * * * * * * * *
 *****************
2*p*p*p*p*p*p*p*p*
 *****************
1*r*h*b*q*k*b*h*r*
 *****************
    Game Start
------------------
Player1=lowercase;Player2=uppercase
command template: FromPosition ToPosition
type 'e' to end the game
Player 1:
```
Say I want to move one of the pawns, So i choose to move the pawn at `b2` and move it to `b3`. So in the prompt id type in
```
Player 1:b2 b3
   a b c d e f g h
 *****************
8*R*H*B*Q*K*B*H*R*
 *****************
7*P*P*P*P*P*P*P*P*
 *****************
6* * * * * * * * *
 *****************
5* * * * * * * * *
 *****************
4* * * * * * * * *
 *****************
3* *p* * * * * * *
 *****************
2*p* *p*p*p*p*p*p*
 *****************
1*r*h*b*q*k*b*h*r*
 *****************
Player 2:
```

The board will update the piece and the other player now plays.

----
### Pieces
----
#### Pawn
Pawns can move 1-2 moves only the first time they are moved, after they can only move 1 space forward or diagonal if they are taking a piece
```
First turn
 * * * * *X* * * *
 *****************
 * * * * *X* * * *
 *****************
 * * * * *P* * * *
 *****************
Other turn
 * * * * * * * * *
 *****************
 * * * * *X* * * *
 *****************
 * * * * *P* * * *
 *****************
Taking piece
 * * * * ** * * *
 *****************
 * * * *X* *X* * *
 *****************
 * * * * *P* * * *
 *****************
```
----
#### Rook
Rooks can only move in straight lines, but can move as many spaces as allows, without going over other pieces.

```
 *X* * * ** * * *
 *****************
 *R*X*X*X*X*X*X*X*
 *****************
 *X* * * * * * * *
 *****************
 ```
----
#### Bishop
Bishops can move diagonal only, as many spaces as allows without going over other pieces.
```
 *X* *X* ** * * *
 *****************
 * *B* * * * * * *
 *****************
 *X* *X* * * * * *
 *****************
 ```

----
#### Knight
Knights can move 2 spaces in and straight direction, then 1 space adjacent to it.
```

 * * *X* *X* * * *
 *****************
 * *X* * * *X* * *
 *****************
 * * * *H* * * * *
 *****************
 * *X* * * *X* * *
 *****************
 * * *X* *X* * * *
```
#### Queen
The Queen can move vertical or horizontal and diagonal.
```

 *X* * *X* * *X* *
 *****************
 * *X* *X* *X* * *
 *****************
 *X*X*X*Q*X*X*X*X*
 *****************
 * *X* *X* *X* * *
 *****************
 *X* * *X* * *X* *
```
----
#### King
The King is the piece you are trying to protect and not be in check/checkmate.  This piece can move 1 space in any direction
```
 * * *X*X**X* * *
 *****************
 * * *X*K*X* * * *
 *****************
 * * *X*X*X* * * *
 *****************
 ```
