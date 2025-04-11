#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define INF 2111111111
using namespace std;

int N, M;

int b[55][55];
vector<pii> viruses;
int safe_count;
int virus_count;
vector<int> combi;
bool visited[55][55];
int ans = INF;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};


int bfs() {
    queue<pii> q;
    for(int i: combi) {
        q.push(viruses[i]);
    }

    int cnt = safe_count;
    fill_n(&visited[0][0], 55*55, false);

    int t = 0;
    while(!q.empty() && cnt > 0) {
        t++;
        int size = q.size();
        for(int i=0; i<size; i++) {
            auto [r, c] = q.front();
            q.pop();
            for(int j=0; j<4; j++) {
                int nr = r + dr[j];
                int nc = c + dc[j];
                if(nr>=0 && nr<N && nc>=0 && nc<N && !visited[nr][nc] && b[nr][nc] != 1) {
                    visited[nr][nc] = true;
                    if(b[nr][nc] == 0) {
                        cnt--;
                    }
                    q.push({nr, nc});
                }
            }
        }
    }

    if(cnt>0) {
        t = INF;
    }

    return t;
}

void make_combi(int cnt, int prev) {
    if(cnt == M) {
        // for(int e: combi) {
        //     cout << e << ' ';
        // }
        // cout << '\n';
        ans = min(ans, bfs());
        return;
    }

    for(int i=prev+1; i<virus_count; i++) {
        combi.push_back(i);
        make_combi(cnt+1, i);
        combi.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int x;
            cin >> x;
            b[i][j] = x;
            if(x == 2) {
                viruses.push_back({i, j});
                virus_count++;
            } else if(x == 0) {
                safe_count++;
            }
        }
    }

    make_combi(0, -1);

    ans = ans == INF ? -1 : ans;
    cout << ans; 

    return 0;
}