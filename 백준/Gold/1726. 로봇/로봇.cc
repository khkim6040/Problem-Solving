#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define pll pair<ll, ll>
using namespace std;

struct Node {
    int r, c, d, cnt;

    bool operator< (const Node &other) const {
        return cnt > other.cnt;
    }

    void prt() {
        cout << r << ' ' << c << ' ' << d << ' ' << cnt << '\n';
    }
};

int N, M;
int b[105][105];
bool visited[105][105][5];

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int get_turn_cnt(int cur, int next) {
    if(cur+next == 3 || cur+next == 7) {
        // 반대방향
        return 2;
    } else if(cur == next) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >> b[i][j];
        }
    }

    int r1, c1, d1, r2, c2, d2;
    cin >> r1 >> c1 >> d1 >> r2 >> c2 >> d2;

    queue<Node> q;
    q.push({r1, c1, d1, 0});
    visited[r1][c1][d1] = true;

    int ans = -1;
    while(!q.empty()) {
        Node cur = q.front();
        q.pop();

        // cur.prt();

        if(cur.r == r2 && cur.c == c2 && cur.d == d2) {
            ans = cur.cnt;
            break;
        }

        // 직진
        int r = cur.r;
        int c = cur.c;
        int cnt = 0;

        while(cnt<3) {
            cnt++;
            r = r + dr[cur.d-1];
            c = c + dc[cur.d-1];
            if(r<=0 || r>N || c<=0 || c>M || b[r][c]==1) break;
            if(visited[r][c][cur.d]) continue;
            visited[r][c][cur.d] = true;
            q.push({r, c, cur.d, cur.cnt+1});
        }

        // 좌/우 회전
        vector<int> dirs;
        if(cur.d<=2) {
            dirs.push_back(3);
            dirs.push_back(4);
        } else {
            dirs.push_back(1);
            dirs.push_back(2);
        }

        for(int i=0; i<2; i++) {
            int d = dirs[i];
            if(visited[cur.r][cur.c][d]) continue;
            visited[cur.r][cur.c][d] = true;
            q.push({cur.r, cur.c, d, cur.cnt+1});
        }
    }

    cout << ans;

    return 0;
}