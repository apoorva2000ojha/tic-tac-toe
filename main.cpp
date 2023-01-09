#include <bits/stdc++.h>

using namespace std;

// interface -> C++ does not have interfaces
// Abstract Class -> class jiska object nahi ban sakta 
class Piece {
public:
    virtual string print() = 0;
};

class Zero: public Piece{
public:
    Zero(){

    }
    string print() {
        return "O";
    }
};

class Cross: public Piece{
public:
    Cross(){
     
    }
    string print() {
        return "X";
    }
};

class Block{
public:
    int x;
    int y;
    Piece *p;
    Block(int X, int Y){
        x= X;
        y=Y;
        p= NULL;
    }

    string print() {
        if (p == NULL) {
            return "   ";
        }
        else {
            return " " + p->print() + " ";
        }
    }
};

class Board{
public:
    vector <vector <Block *>> blocks; // instance variable
    Board(){
        blocks = vector<vector<Block *>>(3, vector<Block *>(3, NULL));
        for(int i =0; i<3; i++){
            for(int j=0; j<3; j++){
                blocks[i][j] = new Block(i, j);
            }
        }  
    }
    string print(){
        string s = "+---+---+---+\n|";
        for(int i =0; i<3; i++){
            for(int j=0; j<3; j++){
                s = s + blocks[i][j]->print() + "|";
            }
            s = s + "\n+---+---+---+\n";

            if (i < 2)
                s += "|";
        }

        return s;
    }
};

class Game{
    public:
    Board* board;
    int turn;
    bool isComplete;
    Game(){
        board = new Board();
        turn = 0;
        isComplete = false;
    }

    void play(){
        int x;
        int y;
        cout << "Turn of " << turn << endl;
        cin >> x >> y;
        if(board->blocks[x][y]->p != NULL){
            return;
        }
        if(turn==0){
            board->blocks[x][y]->p = new Zero(); 
            turn = 1; 
        }
        else {
            board->blocks[x][y]->p = new Cross(); 
            turn = 0; 
        }

        checkWin();
    }
    void print(){
        cout<<board->print() + "\n";
    } 
  void checkWin(){
    // check for rows
    for(int i=0; i<3; i++){
        if(board->blocks[i][0]->p != NULL && board->blocks[i][1]->p != NULL &&
         board->blocks[i][2]->p != NULL &&
         board->blocks[i][0]->p->print()==board->blocks[i][1]->p->print()&&
         board->blocks[i][1]->p->print()==board->blocks[i][2]->p->print()){
             cout<< "Player " << 1 - turn << " wins!" << endl;
             isComplete=true;
             return;
         }
         
         // check for columns
         if(board->blocks[0][i]->p != NULL && board->blocks[1][i]->p != NULL &&        board->blocks[2][i]->p != NULL &&
         board->blocks[0][i]->p->print()==board->blocks[1][i]->p->print()&&
         board->blocks[1][i]->p->print()==board->blocks[2][i]->p->print()){
             cout<< "Player " << 1 - turn << " wins!" << endl;
             isComplete=true;
             return;
         }
                  //check for diagonals
         if(board->blocks[0][0]->p != NULL && board->blocks[1][1]->p != NULL &&
         board->blocks[2][2]->p != NULL &&
         board->blocks[0][0]->p->print()==board->blocks[1][1]->p->print()&&
         board->blocks[1][1]->p->print()==board->blocks[2][2]->p->print()){
             cout<< "Player " << 1 - turn << " wins!" << endl;
             isComplete=true;
             return;
         }
         if(board->blocks[0][2]->p != NULL && board->blocks[1][1]->p != NULL &&        board->blocks[2][0]->p != NULL &&
         board->blocks[0][2]->p->print()==board->blocks[1][1]->p->print()&&
         board->blocks[1][1]->p->print()==board->blocks[2][0]->p->print()){
             cout<< "Player " << 1 - turn << " wins!" << endl;
             isComplete=true;
             return;
         }
    }

    // Check for draw
    bool isDraw = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board->blocks[i][j]->p == NULL) {
                isDraw = false;
                break;
            }
        }
    }

    if (isDraw) {
        cout << "It's a draw!" << endl;
        isComplete = true;
    }
}
};

int main() {
    Game* game;
    game = new Game();
    game->print();
    while(game->isComplete == false){
        game->play();
        game->print();
    }

}
