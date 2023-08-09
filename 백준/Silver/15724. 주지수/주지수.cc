#include <iostream>
using namespace std;

int N, M, K;
int mat[1026][1026];
int dp[1026][1026];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >> mat[i][j];
        }
    }    

    for(int i=1; i<=N; i++) {
        int temp = 0;
        for(int j=1; j<=M; j++) {
            temp += mat[i][j];
            dp[i][j] = dp[i-1][j] + temp;
        }
    }

    cin >> K;
    while(K--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << '\n';
    }
    return 0;
}