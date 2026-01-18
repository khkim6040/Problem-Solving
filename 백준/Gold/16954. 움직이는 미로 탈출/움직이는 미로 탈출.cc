#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

char b[9][9];
char next_b[9][9];

int dr[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int N = 8;

void make_next() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i==0) {
                next_b[i][j] = '.';
            } else {
                next_b[i][j] = b[i-1][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> b[i][j];
        }
    }

    queue<pii> q;
    q.push({N-1, 0});

    int cnt = 0;
    bool flag = false;
    while(!q.empty() && !flag) {
        cnt++;
        int size = q.size();
        for(int i=0; i<size; i++) {
            pii cur = q.front();
            q.pop();

            // cout << cur.first << ' ' << cur.second << '\n';

            if(cnt==8) {
                flag = true;
                break;
            }

            make_next();
            for(int j=0; j<9; j++) {
                int r = cur.first + dr[j];
                int c = cur.second + dc[j];
                if(r<0 || r>=N || c<0 || c>=N) continue;
                if(b[r][c] == '#' || next_b[r][c] == '#') continue;
                q.push({r, c});
            }
        }
        memcpy(&b[0][0], &next_b[0][0], sizeof(b));
        // cout << '\n';
    }

    cout << (flag ? 1 : 0);
    
    return 0;
}