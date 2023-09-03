#include <iostream>
#define INF 211111111
using namespace std;

int N, M;
int up[1005][1005]; // 시작지점(1, 1)에서 상승 상태로 (i, j)까지 최대 점수  
int down[1005][1005]; // 종료지점(1, M)에서 하강 상태로 (i, j)까지 최대 점수 
int board[1005][1005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fill(up[0], up[0]+1005*1005, -INF);
    fill(down[0], down[0]+1005*1005, -INF);
    cin >> N >> M;
    for(int i=N; i>=1; i--) {
        for(int j=1; j<=M; j++) {
            cin >> board[i][j];
        }
    }
    // 상승
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(i==1 && j==1) {
                up[i][j] = board[i][j];
                continue;
            }
            up[i][j] = max(up[i-1][j], up[i][j-1]) + board[i][j];
        }
    }    
    // 하강
    for(int i=1; i<=N; i++) {
        for(int j=M; j>=1; j--) {
            if(i==1 && j==M) {
                down[i][j] = board[i][j];
                continue;
            }
            down[i][j] = max(down[i-1][j], down[i][j+1]) + board[i][j];
        }
    }
    // 종합
    int answer = -INF;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            answer = max(answer, up[i][j]+down[i][j]);
        }
    }
    
    cout << answer;
    return 0;

}