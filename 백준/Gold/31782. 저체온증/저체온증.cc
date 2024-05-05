#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
typedef long long ll;
using namespace std;

struct Point {
    int r;
    int c;
};
int N, K, M;
char b[2005][2005];
bool visited[2005][2005];
bool check_[2005][2005];

queue<Point> q;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

bool check(int r, int c) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < N && nc >= 0 && nc < M && b[nr][nc] == 'O') {
            cnt++;
        }
    }
    return cnt >= 2;
}

void bfs() {
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < M && b[nr][nc] == '.' && !visited[nr][nc] &&
                check(nr, nc)) {
                q.push({nr, nc});
                visited[nr][nc] = true;
                b[nr][nc] = 'O';
            }
        }
    }
}

Point bfs_s(int r, int c) {
    q = queue<Point>();
    q.push({r, c});
    Point max_p = {r, c};
    visited[r][c] = true;
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        if (max_p.r + max_p.c < cur.r + cur.c) {
            max_p = cur;
        }

        for (int i = 0; i < 2; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < M && !visited[nr][nc] && b[nr][nc] == 'O') {
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }

    return max_p;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> b[i][j];
            if (b[i][j] == 'O') {
                // cout << i << j << ' ';
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    bfs();
    // fill(&visited[0][0], &visited[2005][2005], false);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!check_[i][j] && b[i][j] == 'O') {
                int r = i;
                int c = j;
                while (r < N && b[r][j] == 'O') {
                    r++;
                }
                while (c < M && b[i][c] == 'O') {
                    c++;
                }
                for (int k = i; k < r; k++) {
                    for (int l = j; l < c; l++) {
                        check_[k][l] = true;
                    }
                }

                if (min(r - i, c - j) > K) {
                    ans += (r - i) * (c - j);
                }
            }
        }
    }

    cout << ans;
}