#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>

#define pii pair<int, int>
#define SIZE 256
using namespace std;

int N, Q;
int M;
int b[SIZE][SIZE];
bool visited[SIZE][SIZE];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void tornado(int level) {
    int tmp[SIZE][SIZE] = {0, };
    int width = pow(2, level);

    for(int cur_r=0; cur_r<N; cur_r+=width) {
        for(int cur_c=0; cur_c<N; cur_c+=width) {
            for(int i=0; i<width; i++) {
                for(int j=0; j<width; j++) {
                    // 원점 기준으로 맞춤
                    int tr = 2*i - width + 1;
                    int tc = 2*j - width + 1;
                    // 90도 회전
                    int ttr = tr;
                    tr = tc;
                    tc = -ttr;
                    // 원래 좌표로 이동
                    int r = (tr + width - 1)/2;
                    int c = (tc + width - 1)/2;

                    // tmp[cur_r+j][cur_c+(width-1-i)] = b[cur_r+i][cur_c+j];
                    tmp[cur_r+r][cur_c+c] = b[cur_r+i][cur_c+j];
                    
                }
            }
        }
    }

    memcpy(&b[0][0], &tmp[0][0], SIZE*SIZE);
}

void melt() {
    int tmp[SIZE][SIZE] = {0, };

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            tmp[i][j] = b[i][j];

            int cnt = 0;
            for(int k=0; k<4; k++) {
                int r = i+dr[k];
                int c = j+dc[k];
                if(r<0 || r>=N || c<0 || c>=N || b[r][c]==0) continue;
                cnt++;
            }
            
            if(cnt<3 && tmp[i][j]>0) tmp[i][j]--;
        }
    }

    memcpy(&b[0][0], &tmp[0][0], SIZE*SIZE);
}

int bfs(int pr, int pc) {
    queue<pii> q;
    q.push({pr, pc});
    visited[pr][pc] = true;
    // pii ret = {b[pr][pc], 1}; // {sum, size}
    int ret = 1;

    while(!q.empty()) {
        pii cur = q.front();
        q.pop();
        
        for(int i=0; i<4; i++) {
            int r = cur.first+dr[i];
            int c = cur.second+dc[i];
            if(r<0 || r>=N || c<0 || c>=N || b[r][c]==0 || visited[r][c]) continue;
            visited[r][c] = true;
            // ret.first += b[r][c];
            // ret.second++;
            ret++;
            q.push({r, c});
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> Q;
    N = pow(2, M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> b[i][j];
        }
    }

    for(int i=0; i<Q; i++) {
        int L;
        cin >> L;
        // cout << L << '\n';
        tornado(L);
        // for(int i=0; i<N; i++) {
        //     for(int j=0; j<N; j++) {
        //         cout << b[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        melt();
    }
    
    int total = 0;
    int max_comp_size = 0;

    // int cnt = 1;
    // for(int i=1; i<=16; i++) {
    //     for(int j=1; j<=16; j++) {
    //         // cout << b[i][j] << ' ';
    //         cout << cnt++ << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            total += b[i][j];
            if(b[i][j] == 0 || visited[i][j]) continue;
            // pii ret = bfs(i, j);
            // total += ret.first;
            // max_comp_size = max(max_comp_size, ret.second);
            int ret = bfs(i, j);
            max_comp_size = max(max_comp_size, ret);
        }
    }

    cout << (max_comp_size == 0 ? 0 : total) << '\n' << max_comp_size;


    return 0;
}