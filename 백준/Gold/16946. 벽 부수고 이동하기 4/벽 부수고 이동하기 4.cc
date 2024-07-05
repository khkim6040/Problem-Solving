#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int b[1005][1005];
bool visited[1005][1005];
pair<int, int> mark[1005][1005];  // {index, size}
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int N, M;

void bfs(int r, int c, const int idx) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;

    queue<pair<int, int>> qq;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        qq.push(cur);
        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if (b[nr][nc] == 0 && !visited[nr][nc]) {
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }

    int s = qq.size();
    while (!qq.empty()) {
        auto cur = qq.front();
        qq.pop();
        mark[cur.first][cur.second] = {idx, s};
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    fill_n(&b[0][0], 1005 * 1005, -1);
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            b[i][j + 1] = s[j] - '0';
        }
    }

    int idx = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (b[i][j] == 0 && !visited[i][j]) {
                bfs(i, j, idx++);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (b[i][j] == 1) {
                vector<bool> t_visited(idx + 1);
                int sum = 1;
                for (int k = 0; k < 4; k++) {
                    int r = i + dr[k];
                    int c = j + dc[k];
                    if (b[r][c] == 0 && !t_visited[mark[r][c].first]) {
                        t_visited[mark[r][c].first] = true;
                        sum += mark[r][c].second;
                    }
                }
                cout << sum % 10;
            } else {
                cout << 0;
            }
        }
        cout << '\n';
    }

    return 0;
}