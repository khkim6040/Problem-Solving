#include <iostream>
using namespace std;

int N;
char board[5005][5005];
bool is_checked[5005][5005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (!is_checked[i][j]) {
                if (board[i][j] == 'R') {
                    bool checker = board[i + 1][j] == 'R' && board[i + 1][j + 1] == 'R' && !is_checked[i + 1][j] && !is_checked[i + 1][j + 1];
                    if (!checker) {
                        cout << 0;
                        return 0;
                    }
                    is_checked[i][j] = true;
                    is_checked[i + 1][j] = true;
                    is_checked[i + 1][j + 1] = true;
                } else {
                    bool checker = board[i][j + 1] == 'B' && board[i + 1][j + 1] == 'B' && !is_checked[i][j + 1] && !is_checked[i + 1][j + 1];
                    if (!checker) {
                        cout << 0;
                        return 0;
                    }
                    is_checked[i][j] = true;
                    is_checked[i][j + 1] = true;
                    is_checked[i + 1][j + 1] = true;
                }
            }
        }
    }

    cout << 1;

    return 0;
}