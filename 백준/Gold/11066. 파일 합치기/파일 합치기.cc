#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define pii pair<int, int>

int N, T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> vec(N);
        for (int i = 0; i < N; i++) {
            cin >> vec[i];
        }

        ll dp[505][505];
        ll pref_sum[505][505];
        for (int i = 0; i < N; i++) {
            dp[i][i] = 0;
            pref_sum[i][i] = vec[i];
            if (i < N - 1) {
                dp[i][i + 1] = vec[i] + vec[i + 1];
                pref_sum[i][i + 1] = vec[i] + vec[i + 1];
            }
        }

        for (int k = 2; k <= N - 1; k++) {
            for (int i = 0; i + k < N; i++) {
                pref_sum[i][i + k] = pref_sum[i][i + 1] + pref_sum[i + 2][i + k];
            }
        }

        for (int k = 2; k <= N - 1; k++) {
            for (int i = 0; i + k < N; i++) {
                dp[i][i + k] = 99999999999;
                for (int j = i; j < i + k; j++) {
                    dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j + 1][i + k] + pref_sum[i][i + k]);
                }
            }
        }

        cout << dp[0][N - 1] << '\n';
    }
    return 0;
}
