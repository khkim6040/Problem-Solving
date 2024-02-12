#include <iostream>
using namespace std;

int N, M;
int board[505][505];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool visited[505][505];

int max_value;

void bfs(int pre_y, int pre_x, int count, int value) {
    if (count == 4) {
        max_value = max(max_value, value);
        return;
    }

    visited[pre_y][pre_x] = true;
    for (int i = 0; i < 4; i++) {
        int x = pre_x + dx[i];
        int y = pre_y + dy[i];
        if (!visited[y][x] && x > 0 && y > 0 && x <= M && y <= N) {
            visited[y][x] = true;
            bfs(y, x, count + 1, value + board[y][x]);
            visited[y][x] = false;
        }
    }
    visited[pre_y][pre_x] = false;
}

void calculateConcaveBlock(int y, int x) {
    int cross_value = board[y][x];
    for (int i = 0; i < 4; i++) {
        cross_value += board[y + dy[i]][x + dx[i]];
    }
    for (int i = 0; i < 4; i++) {
        max_value = max(max_value, cross_value - board[y + dy[i]][x + dx[i]]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            bfs(i, j, 1, board[i][j]);
            calculateConcaveBlock(i, j);
        }
    }

    cout << max_value;
    return 0;
}