#include <iostream>
#include <string>
using namespace std;

int count;
int board[10][10];
bool row_checker[10][10];
bool col_checker[10][10];
bool box_checker[10][10];
bool is_answer;

void printBoard() {
    for(int i=1; i<=9; i++) {
        for(int j=1; j<=9; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

void backTrack(int row, int col) {
    if(row==10) {
        is_answer = true;
        printBoard();
        return;
    }
    // 값 존재 시 다음거 호출
    if(board[row][col]) {
        backTrack(row+col/9, col%9+1);
        return;
    }
    
    for(int k=1; k<=9; k++) {
        if(!row_checker[row][k] && !col_checker[col][k] && !box_checker[3*((row-1)/3)+(col-1)/3][k]) {
            board[row][col] = k;
            row_checker[row][k] = col_checker[col][k] = box_checker[3*((row-1)/3)+(col-1)/3][k] = true;
            backTrack(row+col/9, col%9+1);
            if(is_answer) break;
            board[row][col] = 0;
            row_checker[row][k] = col_checker[col][k] = box_checker[3*((row-1)/3)+(col-1)/3][k] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(int i=1; i<=9; i++) {
        string row;
        cin >> row;
        for(int j=1; j<=9; j++) {
            int value = int(row[j-1])-'0';
            board[i][j] = value;
            if(value!=0) {
                row_checker[i][value] = true;
                col_checker[j][value] = true;
                box_checker[3*((i-1)/3)+(j-1)/3][value] = true;
            }                
        }
    }
    
    backTrack(1, 1);
    
    return 0;
}