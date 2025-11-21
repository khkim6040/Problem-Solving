#include <iostream>

using namespace std;

int b[505][505];
bool visited[505][505];
int N;
int depth[505][505];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int ans;

int dfs(int rr, int cc) {
    if(visited[rr][cc]) return depth[rr][cc];
    visited[rr][cc] = true;
    int ret = 1;

    for(int i=0; i<4; i++) {
        int r = rr + dr[i];
        int c = cc + dc[i];
        if(r<0 || r>=N || c<0 || c>=N || b[r][c] <= b[rr][cc]) continue;
        ret = max(ret, dfs(r, c)+1);
    }

    ans = max(ans, ret);

    return depth[rr][cc] = ret;
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
    

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(visited[i][j]) continue;
            dfs(i, j);
        }
    }

    cout << ans;

    return 0;
}