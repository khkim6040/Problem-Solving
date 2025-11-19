#include <iostream>
#include <queue>
#include <vector>

#define pii pair<int ,int>

using namespace std;

int N;
int b[105][105];
int section[105][105];
bool visited[105][105];


int dr[] = {-1, 1, 0, 0};
int dc[] = { 0, 0, -1, 1};

void fill_num(int rr, int cc, int num) {
    queue<pii> q;

    q.push({rr, cc});
    visited[rr][cc] = true;
    section[rr][cc] = num;

    while(!q.empty()) {
        pii cur = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int r = cur.first + dr[i];
            int c = cur.second + dc[i];

            if(r<0 || r>=N || c<0 || c>=N || b[r][c]==0 || visited[r][c]) continue;
            visited[r][c] = true;
            section[r][c] = num;
            q.push({r, c});
        }
    }
}

int search(int pr, int pc) {
    int num = section[pr][pc];
    bool visited_[105][105] = {false, };

    queue<pii> q;
    // 시작 지점 넣기
    for(int i=0; i<4; i++) {
        int r = pr + dr[i];
        int c = pc + dc[i];
        if(r<0 || r>=N || c<0 || c>=N || b[r][c] != 0) continue;
        visited_[r][c] = true;
        q.push({r, c});
    }

    int ret = 0;
    while(!q.empty()) {
        int size = q.size();
        ret++;

        for(int i=0; i<size; i++) {
            pii cur = q.front();
            q.pop();

            int cr = cur.first;
            int cc = cur.second;
    
            for(int j=0; j<4; j++) {
                int r = cr + dr[j];
                int c = cc + dc[j];
                if(r<0 || r>=N || c<0 || c>=N || section[r][c]==num || visited_[r][c]) continue;
                if(b[r][c] == 1 && section[r][c] != num) {
                    return ret;
                } 
                visited_[r][c] = true;
                q.push({r, c});
            }
        }
    }

    return 2111111111;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> b[i][j];
        }
    }

    int num = 1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(visited[i][j] || !b[i][j]) continue;
            fill_num(i, j, num++);
        }
    }

    int ans = 2111111111;
    // 모든 육지 위치에서 bfs 
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(b[i][j]==0) continue;
            int a = search(i, j);
            // cout << i << ' ' << j << ' ' << a << '\n';
            ans = min(ans, a);
        }
    }
    
    cout << ans;

    return 0;
}