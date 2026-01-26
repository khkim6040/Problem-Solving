#include <iostream>
#include <vector>
#include <queue>

#define U 0
#define D 1
#define L 2
#define R 3
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int W, H;
char b[111][111];
vector<pii> cs;
int dist[111][111][4];

struct Node {
    int r, c, cost, dir;

    bool operator< (const Node &other) const {
        return cost > other.cost;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> W >> H;

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> b[i][j];
            if(b[i][j] == 'C') {
                cs.push_back({i, j});
            }
        }
    }

    pii S = cs[0];
    pii E = cs[1];

    int INF = 211111111;
    fill_n(&dist[0][0][0], 111*111*4, INF);
    priority_queue<Node> q;
    for(int dir=0; dir<4; dir++) {
        dist[S.first][S.second][dir] = 0;
        int r = S.first + dr[dir];
        int c = S.second + dc[dir];
        if(r<0 || r>=H || c<0 || c>=W || b[r][c] == '*') continue;
        dist[r][c][dir] = 0;
        q.push({r, c, 0, dir});
    }

    int ans = INF;
    while(!q.empty()) {
        Node cur = q.top();
        q.pop();

        if(cur.r == E.first && cur.c == E.second) {
            ans = cur.cost;
            break;
        }

        for(int dir=0; dir<4; dir++) {
            // 180도 안됨
            if(dir+cur.dir==1 || dir+cur.dir==5) continue;
            int r = cur.r + dr[dir];
            int c = cur.c + dc[dir];
            if(r<0 || r>=H || c<0 || c>=W || b[r][c] == '*') continue;
            int cost = cur.cost;
            if(dir != cur.dir) cost++;

            if(cost >= dist[r][c][dir]) continue;
            dist[r][c][dir] = cost;
            q.push({r, c, cost, dir});
        }
    }

    // for(int i=0; i<H; i++) {
    //     for(int j=0; j<W; j++) {
    //         dist[i][j] = dist[i][j] == INF ? -1 : dist[i][j];
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << ans;
    

    return 0;
}