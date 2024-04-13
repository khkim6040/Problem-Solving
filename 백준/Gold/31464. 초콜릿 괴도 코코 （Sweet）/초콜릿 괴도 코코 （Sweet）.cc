#include <iostream>
#include <vector>
using namespace std;

int N;
char board[43][43];
int cnt[43][43];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Point {
    int y;
    int x;
};

vector<Point> ans;
int _count;
int dfs_cnt;
bool visited[43][43];

// bool dfs(int r, int c) {
//     if ()
//         dfs_cnt++;
//     for (int i = 0; i < 4; i++) {
//         int r =
//     }
// }

bool check(int r, int c, int p_r, int p_c) {
    if (visited[r][c]) {
        return false;
    }
    dfs_cnt++;
    visited[r][c] = true;
    bool checker = true;
    for (int k = 0; k < 4; k++) {
        int nr = r + dy[k];
        int nc = c + dx[k];
        if (board[nr][nc] == '#' && !(nr == p_r && nc == p_c)) {
            checker &= check(nr, nc, r, c);
        }
    }

    return checker;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            if (board[i][j] == '#') {
                _count++;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j] == '.') continue;

            board[i][j] = '.';
            for (int k = 0; k < 4; k++) {
                int r = i + dy[k];
                int c = j + dx[k];
                if (board[r][c] == '#') {
                    // cout << i << ' ' << j << ' ' << r << ' ' << c << '\n';
                    dfs_cnt = 0;
                    fill_n(&visited[0][0], 43 * 43, false);
                    if (check(r, c, i, j) && dfs_cnt == _count - 1) {
                        ans.push_back({i, j});
                    }
                    break;
                }
            }

            board[i][j] = '#';
        }
    }

    cout << ans.size() << '\n';
    for (auto ele : ans) {
        cout << ele.y << ' ' << ele.x << '\n';
    }

    return 0;
}