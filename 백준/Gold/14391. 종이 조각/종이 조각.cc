#include <iostream>
#include <string>

using namespace std;

int N, M;
int b[5][5];
int dp[5][5][5][5];

int get_vert_total(int r1, int r2, int c) {
    int ret = 0;
    for(int i=r1; i<=r2; i++) {
        ret *= 10;
        ret += b[i][c];
    }

    return ret;
}

int get_hori_total(int r, int c1, int c2) {
    int ret = 0;
    for(int i=c1; i<=c2; i++) {
        ret *= 10;
        ret += b[r][i];
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    
    for(int i=0; i<N; i++) {
        string str;
        cin >> str;
        for(int j=0; j<M; j++) {
            b[i][j] = str[j] - '0';
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            dp[i][j][i][j] = b[i][j];
            for(int gap=1; gap<4; gap++) {
                // 새로
                if(i+gap < N) {
                    dp[i][j][i+gap][j] = max(dp[i][j][i+gap-1][j] + b[i+gap][j], get_vert_total(i, i+gap, j));
                }
                // 가로
                if(j+gap < M) {
                    dp[i][j][i][j+gap] = max(dp[i][j][i][j+gap-1] + b[i][j+gap], get_hori_total(i, j, j+gap));
                }
            }
        }
    }

    for(int h=1; h<N; h++) {
        for(int w=1; w<M; w++) {
            // 시작지점
            for(int r=0; r+h<N; r++) {
                for(int c=0; c+w<M; c++) {
                    // 가능한 분할 모두 고려
                    int tmp = 0;
                    int row_end = r+h;
                    int col_end = c+w;
                    for(int k=0; k<h; k++) {
                        tmp = max(tmp, dp[r][c][r+k][col_end]+dp[r+k+1][c][row_end][col_end]);
                    }
                    for(int k=0; k<w; k++) {
                        tmp = max(tmp, dp[r][c][row_end][c+k]+dp[r][c+k+1][row_end][col_end]);
                    }
                    dp[r][c][r+h][c+w] = tmp;
                }
            }
        } 
    }

    cout << dp[0][0][N-1][M-1];
    
    return 0;
}