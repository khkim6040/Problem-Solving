#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define INF 2000000000

int N;
int b[1005][3];
int dp0[1005][3];
int dp1[1005][3];
int dp2[1005][3];
int dp[3][1005][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> b[i][j];
        }
    }

    // 1st
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                dp[i][1][j] = b[1][j];
            } else {
                dp[i][1][j] = INF;
            }
        }
    }
    // 2~N-1
    for (int k = 0; k < 3; k++) {
        for (int i = 2; i <= N - 1; i++) {
            for (int j = 0; j < 3; j++) {
                dp[k][i][j] = min(dp[k][i - 1][(j + 1) % 3], dp[k][i - 1][(j + 2) % 3]) + b[i][j];
            }
        }
    }
    // N
    int ans = INF;
    for (int k = 0; k < 3; k++) {
        for (int j = 0; j < 3; j++) {
            if (k == j) {
                dp[k][N][j] = INF;
            } else {
                dp[k][N][j] = min(dp[k][N - 1][(j + 1) % 3], dp[k][N - 1][(j + 2) % 3]) + b[N][j];
            }
            ans = min(ans, dp[k][N][j]);
        }
    }

    cout << ans;

    return 0;
}