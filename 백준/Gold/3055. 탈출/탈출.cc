#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define ll long long
#define pii pair<int, int>
using namespace std;

int N, M;
char b[105][105];
char tmp[105][105];
bool visited[105][105];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

pii D, S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> b[i][j];
            if(b[i][j] == 'D') {
                D.first = i;
                D.second = j;
            } else if(b[i][j] == 'S') {
                S.first = i;
                S.second = j;
                b[i][j] = '.';
            }
        }
    }

    queue<pii> q;
    q.push(S);
    visited[S.first][S.second] = true;

    int ans = 0;
    while(!q.empty()) {
        memcpy(tmp, b, sizeof(b));

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(b[i][j] != '*') continue;
                for(int k=0; k<4; k++) {
                    int r = i + dr[k];
                    int c = j + dc[k];

                    if(r<0 || r>=N || c<0 || c>=M || b[r][c] != '.') continue;
                    tmp[r][c] = '*';
                }
            }
        }
        memcpy(b, tmp, sizeof(tmp));


        // cout << ans << '\n';
        // for(int i=0; i<N; i++) {
        //     for(int j=0; j<M; j++) {
        //         cout << b[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        int size = q.size();

        for(int i=0; i<size; i++) {
            pii cur = q.front();
            q.pop();

            if(cur == D) {
                cout << ans;
                return 0;
            }

            for(int j=0; j<4; j++) {
                int r = cur.first + dr[j];
                int c = cur.second + dc[j];

                if(r<0 || r>=N || c<0 || c>=M || visited[r][c] || b[r][c] == 'X' || b[r][c] == '*') continue;
                visited[r][c] = true;
                q.push({r, c});
            }
        }
        ans++;
    }
    
    cout << "KAKTUS";
    
    return 0;
}