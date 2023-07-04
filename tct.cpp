#include <iostream>
using namespace std;

char board[3][3] {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void printBoard() {
    for(int i = 0; i<=2; i++) {
        for (int j = 0; j<=2; j++) {
           cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

//     0 1 2
//    -------
// 0 | 1 2 3
// 1 | 4 5 6
// 2 | 7 8 9

void playerMove(char player) {
    int move;
    cout << "Player " << player << "'s turn\n";
    cout << "Enter your move (1-9): ";
    cin >> move; // 7

    int row = (move-1) / 3; // 2
    int col = (move-1) % 3; // 0

    if (board[row][col] != 'X' && board[row][col] != 'O' ) {
        board[row][col] = player;
    } else {
        cout << "Invalid move. Try again.\n";
        playerMove(player);
    }
    
}

bool checkWin(char player) {
    for (int i = 0; i<=2; i++) {
        if(board[i][0] == player &&  board[i][1] == player &&  board[i][2] == player) {
            return true;
        }
        if(board[0][i] == player &&  board[1][i] == player &&  board[2][i] == player) {
            return true;
        }
    }

    if (board[0][0] == player &&  board[1][1] == player &&  board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player &&  board[1][1] == player &&  board[2][0] == player) {
        return true;
    }

    return false;
    
}

void gameLoop() {
    int moves = 0;
    char player = 'X';
    while (moves < 9) {
        printBoard();
        playerMove(player);
        if (checkWin(player)) {
            printBoard();
            cout << "Player " << player << " wins!\n";
            return;
        }
        player = (player == 'X') ? 'O' : 'X'; // Change player
        moves++; // Increment move
    }
    printBoard();
    cout << "It's a tie!\n";
}

int main() {

    gameLoop();


    return 0;
}