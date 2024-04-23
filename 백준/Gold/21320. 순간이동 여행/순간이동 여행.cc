#include <iostream>

using namespace std;
typedef long long ll;
#define MOD 1000000007

int N, K;

ll dp[3005];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = 1;
        for (int j = 0; j <= i - 2; j++) {
            dp[i] = (dp[i] + 2 * dp[j]) % MOD;
        }
    }

    ll ans = 0;

    for (int i = 0; i <= N - 2; i++) {
        ans = (ans + dp[i]) % MOD;
    }

    // cout << ans << '\n';
    int D = K - 1;  // depth

    ans = (ans + dp[N - D - 1]) % MOD;
    for (int i = 0; i <= D - 1; i++) {
        ans = (ans + dp[N - D - 1 + i]) % MOD;
    }

    cout << ans;
    return 0;
}