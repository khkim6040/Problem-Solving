#include <iostream>
using namespace std;

int N, M, init_x, init_y, K;
int board[25][25];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Dice {
    int x, y;
    int value[6];  // value of each side of the dice
    // indexes of up, front, right side of the dice
    int up = 3;
    int front = 4;
    int right = 5;
};
Dice d;

void alterDirection(int order) {
    if (order == 1) {
        swap(d.up, d.right);
        d.up = (d.up + 3) % 6;
    } else if (order == 2) {
        swap(d.up, d.right);
        d.right = (d.right + 3) % 6;
    } else if (order == 3) {
        swap(d.up, d.front);
        d.front = (d.front + 3) % 6;
    } else {
        swap(d.up, d.front);
        d.up = (d.up + 3) % 6;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> init_y >> init_x >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    d.x = init_x;
    d.y = init_y;
    int order;
    for (int i = 0; i < K; i++) {
        cin >> order;
        // move
        d.x += dx[order - 1];
        d.y += dy[order - 1];
        if (d.x < 0 || d.x >= M || d.y < 0 || d.y >= N) {
            // cout << i << ' ' << order << '\n';
            d.x -= dx[order - 1];
            d.y -= dy[order - 1];
            continue;
        }
        // change direction of up, front, right of the dice
        alterDirection(order);
        // copy number
        if (board[d.y][d.x] == 0) {
            int down = (d.up + 3) % 6;
            board[d.y][d.x] = d.value[down];
        } else {
            int down = (d.up + 3) % 6;
            d.value[down] = board[d.y][d.x];
            board[d.y][d.x] = 0;
        }

        cout << d.value[d.up] << '\n';
    }
    return 0;
}