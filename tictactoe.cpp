#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int playerTurn = 1;
char currentMarker;

void drawBoard() {
    system("clear"); // Use "cls" for Windows
    cout << "\nTic-Tac-Toe\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "-----------\n";
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

void placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Slot already taken. Try again!\n";
    } else {
        board[row][col] = currentMarker;
        if (checkWin()) {
            drawBoard();
            cout << "Player " << playerTurn << " wins!\n";
            exit(0);
        } else if (isDraw()) {
            drawBoard();
            cout << "It's a draw!\n";
            exit(0);
        }
        playerTurn = (playerTurn == 1) ? 2 : 1;
        currentMarker = (currentMarker == 'X') ? 'O' : 'X';
    }
}

int main() {
    cout << "Player 1, choose your marker (X or O): ";
    cin >> currentMarker;
    if (currentMarker != 'X' && currentMarker != 'O') {
        cout << "Invalid marker! Defaulting to X." << endl;
        currentMarker = 'X';
    }
    drawBoard();
    while (true) {
        int slot;
        cout << "Player " << playerTurn << "'s turn. Enter slot number: ";
        cin >> slot;
        if (slot < 1 || slot > 9) {
            cout << "Invalid input! Try again.\n";
            continue;
        }
        placeMarker(slot);
        drawBoard();
    }
    return 0;
}
