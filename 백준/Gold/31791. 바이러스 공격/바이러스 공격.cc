#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

struct Node {
    int r;
    int c;
    int t;
    bool operator<(const Node& other) const {
        return t > other.t;
    }
};

int N, M;
int TG, TB, X, B;
char b[1005][1005];
int cost[1005][1005];
bool visited[1005][1005];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
priority_queue<Node> pq;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> TG >> TB >> X >> B;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> b[i][j];
            if (b[i][j] == '*') {
                pq.push({i, j, 0});
                visited[i][j] = true;
            }
        }
    }

    fill_n(&cost[0][0], 1005 * 1005, 2000000000);
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        cost[cur.r][cur.c] = cur.t;
        // visited[cur.r][cur.c] = true;

        if (cost[cur.r][cur.c] > TG) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if (nr > 0 && nr <= N && nc > 0 && nc <= M && !visited[nr][nc]) {
                pq.push({nr, nc, b[nr][nc] == '#' ? cur.t + TB + 1 : cur.t + 1});
                visited[nr][nc] = true;
            }
        }
    }

    bool flag = false;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (cost[i][j] > TG || !visited[i][j]) {
                flag = true;
                cout << i << ' ' << j << '\n';
            }
            // cout << cost[i][j] << ' ';
        }
        // cout << '\n';
    }

    if (!flag) {
        cout << -1;
    }
    return 0;
}