# Tic-Tac-Toe
This program represnts a game of Tic Tac Toe using the concepts of Object Oriented Programming(OOP) such as inheritance, encapsulation and polymorphism.
<li>The piece is an abstract class and has no properties defined of its own it contains a virtual function. Piece has two child classes Zero and Cross and they both implement print function.
<li>The second is the class Block, this class represents a single box in the tic tac toe game. The class has three instance variables x, y, these are the coordinates of the block and p which is the pointer to the Piece. The Block class also has a constructor that initializes the varibales and contains a print functions that returns a string representation of the box.
<li>The third is the class Board, it represents the complete board of the tic tac to game.It contains the instance variable blocks, which is a 2D vector of pointers to Block objects. It also contains a constructor that initializes the blocks vector. It has a print function that returns the the board in the form of a string.
<li>The fourth class is the Game class that represents the complete game of tic tac toe. It has thress instance variables board which is a pointer to the object Board, turn which defines the current players turn, and isComplete which tells the state of the game whether the game is finished or not. The constructor Game initializes all these variable. The play function take the input of the x, y coordinates and lets the player take its turn. The print function print the currnt state of the board after the turn and the checkWin function checks which player won the game. The isDraw functions check whether the game ended in a draw.

The following OOP concepts are used in the program
<li><b>Inheritance</b> The Zero and Cross class inherit from the Piece class and they override the print function.
<li><b>Encapsulation</b> This allows us to hide the internal representation of the Piece Block Board and Game class from the main function and also from each other.
<li><b>Polymorphism</b> The Piece class has a single virtual function print and it is used as a base class for Zero and Cross to implement the print function and could be used if we need another object in addition to Zero and Cross.

The program uses these OOP concepts to create a simple game of tic-tac-toe that allows two players to take turns placing either an "O" or an "X" on a 3x3 grid until one of them gets three in a row or all of the spaces are filled. The game keeps track of the current player's turn and checks for a win after each move.
