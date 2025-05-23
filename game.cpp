#include <iostream>
#include<limits>
#include<conio.h>  // for press()
#include<cctype>
#include"ClearScreen.hpp"//this for clear screen in cross platform window/mas/unix 
#include"sleep.hpp" //this for sleep program 



//this is my acual file main file for this game 
using namespace std;
// Function to print the game board
void printBoard(char board[3][3]) {// 
    cout << "\n";
    for(int i = 0; i < 3; i++) {

        cout<<"\033[30m |\033[0m";
        for(int p =0;p<3;p++){
        //if player x move so it printed green 
        if(board[i][p]=='X') cout<<"\033[32m "<<board[i][p]<<" \033[0m";
         //if player O move so it printed blue 
        else if(board[i][p]=='O') cout<<"\033[36m "<<board[i][p]<<" \033[0m";
        
        //otherwise it printed as a bydefult color 
        else cout<<"\033[30m "<<board[i][p]<<" \033[0m";

        cout<<"\033[30m|\033[0m";
        }
        cout<<endl;
        if(i < 2) cout << "\033[30m -------------\033[0m" << endl;

    
        
    }
    cout << "\n";
}

// Function to check if there's a winner
bool checkWinner(char board[3][3], char player) {
    // Check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    
    // Check columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    
    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    
    return false;
}

// Function to check if the board is full (draw)
bool isBoardFull(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j]!='X'&&board[i][j]!='O')
                return false;
        }
    }
    return true;
}

int main() {
    short n ;
    do{
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    
     
    

        char currentPlayer = 'X';
        bool gameOver = false;
    
        cout << "Welcome to Tic Tac Toe!" << endl;
        cout << "Enter positions (1-9) as shown below:" << endl;
    
   

    while(!gameOver){
        
        
        // Print current board
        printBoard(board);
        
        // Get player move
        
        int position;
        currentPlayer =='X'?cout<<"\033[32m":cout<<"\033[36m";
        cout << "Player " << currentPlayer<<"|->";
        cin>>position;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//clear buffer 
          

        cout<<"\033[0m";//reset color 
        // Convert position to array indices
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        
        // Check if move is valid
        if(position < 1 || position > 9 ||  board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "\033[31m Invalid move! Try again.\033[0m" << endl;
            sleep_program(100);
            continue;
        }
        
        // Make the move
        board[row][col] = currentPlayer;
        
        // Check for winner
        if(checkWinner(board, currentPlayer)) {
            printBoard(board);
            int count = 0;
            
            for(int i =30;i<38;i++){
              cout<<"\033["<<i<<"m";
              cout << "Player "<< currentPlayer <<" wins!\033[0m" << endl;
              sleep_program(300);
 
           }
            
            gameOver = true;
        }
        // Check for draw
        else if(isBoardFull(board)) {
            
            printBoard(board);
            cout << "---------*GEME END *-----" << endl;
             sleep_program(100);//each 
            gameOver = true;
        }
        // Switch player
        else currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        
        if(!gameOver)clearScreen();//clear screen 
       
    }
    
    cout<<"\nplay Again : [1]\tExit : [0]       ->";
    cin>>n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//clear buffer
    }while(n);
    
    return 0;
}
