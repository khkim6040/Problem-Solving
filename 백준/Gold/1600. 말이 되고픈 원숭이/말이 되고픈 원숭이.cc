#include <iostream>
#include <queue>
#include <vector>

#define INF 2111111111

using namespace std;

struct Node {
    int r;
    int c;
    int k;
};

int K, W, H;
int b[202][202];
int dp[33][202][202];
bool visited[33][202][202];

// 그냥 이동
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// 말처럼 이동
int hr[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int hc[] = {-2, -2, -1, -1, 1, 1, 2, 2};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K >> W >> H;

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> b[i][j];
        }
    }

    fill_n(&dp[0][0][0], 33*202*202, INF);

    // dp[0] 채우기
    queue<Node> q;
    q.push({0, 0, 0});
    dp[0][0][0] = 0;
    visited[0][0][0] = true;
    int cnt = 0;
    while(!q.empty()) {
        int size = q.size();
        cnt++;

        for(int i=0; i<size; i++) {
            Node cur = q.front();
            q.pop();

            for(int j=0; j<4; j++) {
                int r = cur.r + dr[j];
                int c = cur.c + dc[j];
                int k = cur.k;
                if(r<0 || r>=H || c<0 || c>=W || b[r][c]==1 || visited[k][r][c]) continue;
                visited[k][r][c] = true;
                dp[k][r][c] = cnt;
                q.push({r, c, k});
            }

            for(int j=0; j<8; j++) {
                int r = cur.r + hr[j];
                int c = cur.c + hc[j];
                int k = cur.k+1;
                if(r<0 || r>=H || c<0 || c>=W || b[r][c]==1 || visited[k][r][c]) continue;
                if(k>K) continue;
                visited[k][r][c] = true;
                dp[k][r][c] = cnt;
                q.push({r, c, k});
            }
        }
    }

    int ans = INF;
    for(int k=0; k<=K; k++) {
        ans = min(ans, dp[k][H-1][W-1]);
    }

    cout << (ans == INF ? -1 : ans);


    return 0;
}