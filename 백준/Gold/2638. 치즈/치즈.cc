#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int N, M;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int b[105][105];
int cheeses;
bool is_air[105][105];
bool visited[105][105];


void fill_air(int r, int c) {
    // b[r][c] == 0 인 상태에서만 호출된다고 가정
    visited[r][c] = true;
    is_air[r][c] = true;

    for(int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr<0 || nr>=N || nc<0 || nc>=M || b[nr][nc] == 1 || visited[nr][nc]) continue;
        fill_air(nr, nc);
    }
}

void detect_air() {
    fill_n(&visited[0][0], 105*105, false);
    fill_n(&is_air[0][0], 105*105, false);

    for(int i=0; i<N; i++) {
        if(b[i][0] == 1) continue;
        if(!visited[i][0]) {
            fill_air(i, 0);
        }
    }
    for(int j=0; j<M; j++) {
        if(b[0][j] == 1) continue;
        if(!visited[0][j]) {
            fill_air(0, j);
        }
    }    
}

int melt() {
    int ret = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(b[i][j] != 1) continue;
            
            int air_cnt = 0;
            for(int k=0; k<4; k++) {
                int r = i + dr[k];
                int c = j + dc[k];
                if(r<0 || r>=N || c<0 || c>=M || is_air[r][c]) {
                    air_cnt++;
                }
            }

            if(air_cnt >= 2) {
                ret++;
                b[i][j] = 0;
            }
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> b[i][j];
            if(b[i][j] == 1) {
                cheeses++;
            }
        }
    }

    int ans = 0;
    while(cheeses) {
        ans++;
        detect_air();
        cheeses -= melt();
    }

    cout << ans;
    
    return 0;
}