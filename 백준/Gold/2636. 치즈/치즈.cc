#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>

using namespace std;

int N, M;
int b[105][105];
bool visited[105][105];
int cnt;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >> b[i][j];
            if(b[i][j]) cnt++;
        }
    }

    queue<pii> next;
    next.push({0, 0});
    visited[0][0] = true;

    int ans = 0;
    int prev = 0;
    while(cnt) {
        ans++;
        prev = cnt;
        queue<pii> q = next;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                pii cur = q.front();
                q.pop();
                for(int j=0; j<4; j++) {
                    int r = cur.first + dr[j];
                    int c = cur.second + dc[j];
                    if(r<0 || r>N+1 || c<0 || c>M+1 || visited[r][c]) continue;
                    visited[r][c] = true;
                    if(b[r][c]) {
                        next.push({r, c});
                        cnt--;
                    } else {
                        q.push({r, c});
                    }
                }
            }
        }
    }

    cout << ans << '\n' << prev;


    return 0;
}