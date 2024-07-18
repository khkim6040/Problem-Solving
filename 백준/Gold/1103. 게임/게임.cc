#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define pii pair<ll, int>

int N, M;
int b[55][55];
int cnt[55][55];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
bool visited[55][55];
bool is_cycle;

int dfs(int r, int c) {
    if (cnt[r][c]) {
        return cnt[r][c];
    }

    bool flag = false;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i] * b[r][c];
        int nc = c + dc[i] * b[r][c];
        if (nr >= 0 && nc >= 0 && nr < N && nc < M && b[nr][nc] != 24) {
            flag = true;
            if (visited[nr][nc]) {
                is_cycle = true;
                return 0;
            }
            visited[nr][nc] = true;
            cnt[r][c] = max(cnt[r][c], dfs(nr, nc) + 1);
            visited[nr][nc] = false;
        }
    }

    if (!flag) {
        cnt[r][c] = 1;
    }

    return cnt[r][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            b[i][j] = s[j] - '0';  // 'H' - '0' == 24
        }
    }

    visited[0][0] = true;
    dfs(0, 0);

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << cnt[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    if (is_cycle) {
        cout << -1;
    } else {
        cout << cnt[0][0];
    }
    return 0;
}
