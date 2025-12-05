#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define INF 2111111111
#define pii pair<int, int>
using namespace std;

struct Node {
    int r, c, d, k;
};

int N, M, K;
int b[1005][1005];
bool visited[1005][1005][15];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        for(int j=0; j<M; j++) {
            b[i][j] = s[j] - '0';
        }
    }

    queue<Node> q;
    q.push({0, 0, 1, 0});
    visited[0][0][0] = true;

    while(!q.empty()) {
        int size = q.size();

        for(int k=0; k<size; k++) {
            Node cur = q.front();
            q.pop();
    
            if(cur.r == N-1 && cur.c == M-1) {
                cout << cur.d;
                return 0;
            }
    
            for(int i=0; i<4; i++) {
                int r = cur.r + dr[i];
                int c = cur.c + dc[i];
                if(r<0 || r>=N || c<0 || c>=M) continue;
                int k = b[r][c] == 1 ? cur.k+1 : cur.k;
                if(k>K) continue;
                if(visited[r][c][k]) continue;
                visited[r][c][k] = true;
                q.push({r, c, cur.d+1, k});
                // cout << r << ' ' << c << ' ' << cur.d+1 << ' ' << k << '\n';
            }
        }
    }

    cout << -1;

    return 0;
}