#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
typedef long long ll;
using namespace std;

int N, M;
int R, C, D;

struct Point {
    int r;
    int c;
    int d;
};

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
int b[55][55];
int clean_cnt;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    cin >> R >> C >> D;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> b[i][j];
        }
    }

    int dir = D;
    if (dir == 1) {
        dir = 3;
    } else if (dir == 3) {
        dir = 1;
    }

    queue<Point> q;
    q.push({R, C, dir});
    clean_cnt++;
    b[R][C] = 2;

    while (true) {
        auto [r, c, d] = q.front();
        q.pop();

        bool cont_flag = false;

        for (int i = 0; i < 4; i++) {
            int nd = (d + i + 1) % 4;
            int nr = r + dr[nd];
            int nc = c + dc[nd];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M && b[nr][nc] == 0) {
                q.push({nr, nc, nd});
                cont_flag = true;
                b[nr][nc] = 2;
                clean_cnt++;
                break;
            }
        }

        if (cont_flag) {
            continue;
        }
        // 뒤쪽 칸
        int nr = r + dr[(d + 2) % 4];
        int nc = c + dc[(d + 2) % 4];
        if (nr >= 0 && nr < N && nc >= 0 && nc < M && b[nr][nc] != 1) {
            q.push({nr, nc, d});
        } else {
            break;
        }
    }

    cout << clean_cnt;
    return 0;
}