#include <iostream>
using namespace std;
typedef long long ll;
#define pii pair<int, int>

int N, M;
int L[1005][1005];
int R[1005][1005];
int dp[1005][1005];
int b[1005][1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> b[i][j];
        }
    }

    fill_n(&dp[0][0], 1005 * 1005, -2111111111);
    fill_n(&L[0][0], 1005 * 1005, -2111111111);
    fill_n(&R[0][0], 1005 * 1005, -2111111111);
    int s = 0;
    for (int j = 1; j <= M; j++) {
        s += b[1][j];
        dp[1][j] = s;
        L[1][j] = s;
        R[1][j] = s;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            L[i][j] = max(dp[i - 1][j], L[i][j - 1]) + b[i][j];
        }
        for (int j = M; j >= 1; j--) {
            R[i][j] = max(dp[i - 1][j], R[i][j + 1]) + b[i][j];
        }
        for (int j = 1; j <= M; j++) {
            dp[i][j] = max(L[i][j], R[i][j]);
        }
    }

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= M; j++) {
    //         cout << L[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= M; j++) {
    //         cout << R[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= M; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[N][M];
    return 0;
}
