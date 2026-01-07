#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define pii pair<int, int>
using namespace std;

struct Node {
    int r, c, cnt;

    bool operator< (const Node &other) const {
        return cnt > other.cnt;
    }
};

int N, M, cnt;
int b[105][105];
int dist[105][105];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            char c;
            cin >> c;
            b[i][j] = c-'0';
            if(b[i][j]==1) cnt++;
            dist[i][j] = 2111111111;
        }
    }

    deque<Node> q;
    q.push_back({1, 1, 0});
    dist[1][1] = 0;

    while(!q.empty()) {
        Node cur = q.front();
        q.pop_front();

        if(cur.r == N && cur.c == M) break;

        for(int i=0; i<4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];
            if(r<=0 || r>N || c<=0 || c>M) continue;
            int d = cur.cnt;
            if(b[r][c]==1) d++;

            if(d < dist[r][c]) {
                dist[r][c] = d;
                if(b[r][c]==0) q.push_front({r, c, d});
                else q.push_back({r, c, d});
            }
        }
    }

    cout << dist[N][M];
    
    return 0;
}