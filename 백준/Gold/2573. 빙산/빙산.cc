#include <iostream>
#include <queue>
#include <vector>

#define pii pair<int, int>

using namespace std;

int b[303][303];
int N, M;
bool visited[303][303];
int melt[303][303];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs(int pr, int pc) {
    visited[pr][pc] = true;

    queue<pii> q;
    q.push({pr, pc});

    while(!q.empty()) {
        pii cur = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int r = cur.first + dr[i];
            int c = cur.second + dc[i];
            if(r<0 || r>=N || c<0 || c>=M || visited[r][c]) continue;
            if(b[r][c] == 0) {
                melt[cur.first][cur.second]++;
                continue;
            }
            visited[r][c] = true;
            q.push({r, c});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> b[i][j];
        }
    }

    int ans = 0;
    int cnt;
    while(true) {
        cnt = 0;
        fill_n(&visited[0][0], 303*303, false);
        fill_n(&melt[0][0], 303*303, 0);
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(b[i][j]==0 || visited[i][j]) continue;
                bfs(i, j);
                cnt++;
            }
        }

        if(cnt != 1) break;
        ans++;

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                b[i][j] = max(0, b[i][j]-melt[i][j]); 
            }
        }
    }

    if(cnt == 0) {
        ans = 0;
    } 
    cout << ans;
}