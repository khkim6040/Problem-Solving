#include <iostream>
#include <algorithm>
using namespace std;
#define INF 2111111111

int N, M;
int board[1005][1005];
int dp[1005][1005][3]; // dp[i][j][k] = k번째 움직임을 했을 때 (i, j)에 도달하는 최소 연료 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >> board[i][j];
        }
    }
    
    fill_n(&dp[0][0][0], 1005*1005*3, INF);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(i==1) {
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = board[i][j];
                continue;
            }
            // 좌하단
            dp[i][j][0] = min(dp[i-1][j+1][1], dp[i-1][j+1][2]) + board[i][j];
            // 하단
            dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + board[i][j];
            // 우하단
            dp[i][j][2] = min(dp[i-1][j-1][0], dp[i-1][j-1][1]) + board[i][j];
        }
    }

    int answer = INF;
    for(int i=1; i<=M; i++) {
        answer = min({answer, dp[N][i][0], dp[N][i][1], dp[N][i][2]});
    }

    cout << answer;
    return 0;
}