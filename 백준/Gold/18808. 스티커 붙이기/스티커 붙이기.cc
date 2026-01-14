#include <iostream>
#include <vector>

using namespace std;

int N, M, K, R, C;
int cnt;
int ans;
int b[44][44];
vector<vector<int>> sticker;

// (r, c)에 sticker 왼쪽 위부터 넣을 수 있는지
bool match(int r, int c) {
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(i+r >= N || j+c >= M) return false;
            if(sticker[i][j] == 1 && b[i+r][j+c] == 1) return false;
        }
    }

    return true;
}

// (r, c)에 sticker 넣음
void paint(int r, int c) {
    bool flag = false;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(sticker[i][j] == 0) continue;
            b[i+r][j+c] = 1;
        }
    }
}

// sticker 90도 시계방향 회전
void turn() {
    // y=0 대칭이동
    vector<vector<int>> tmp1 = sticker;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            int r = R-i-1;
            tmp1[i][j] = sticker[r][j];
        }
    }

    // y=-x 대칭이동
    vector<vector<int>> tmp2;
    tmp2.assign(C, vector<int>(R));
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            tmp2[j][i] = tmp1[i][j];
        }
    }

    // swap R, C 
    int t = R;
    R = C;
    C = t;
    sticker = tmp2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    while(K--) {
        cin >> R >> C;
        cnt = 0;
        sticker.assign(R, vector<int>(C));
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                cin >> sticker[i][j];
                if(sticker[i][j] == 1) cnt++;
            }
        }
        bool flag = false;
        // 최대 3번 90도 회전
        for(int k=0; k<4; k++) {
            // 현재 노트북의 왼쪽 위에서부터 맞춰보기
            for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {
                    if(match(i, j)) {
                        paint(i, j);
                        // for(int i=0; i<N; i++) {
                        //     for(int j=0; j<M; j++) {
                        //         cout << b[i][j] << ' ';
                        //     }
                        //     cout << '\n';
                        // }
                        // cout << '\n';
                        ans += cnt;
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;
            turn();
        }
    }

    cout << ans;
    
    return 0;
}

