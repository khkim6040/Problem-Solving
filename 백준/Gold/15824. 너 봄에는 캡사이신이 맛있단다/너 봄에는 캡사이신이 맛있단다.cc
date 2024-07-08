#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define MAX 300000

ll dp[300005];  // 2의 거듭제곱
vector<ll> vec;
int N;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    dp[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        dp[i] = dp[i / 2] * dp[i / 2] * (i % 2 == 1 ? 2 : 1) % MOD;
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        vec.push_back(x);
    }

    sort(vec.begin(), vec.end());

    ll ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        ll temp = (dp[i] - dp[N - 1 - i] + MOD) % MOD * vec[i] % MOD;
        ans = (ans + temp % MOD) % MOD;
        // cout << temp << '\n';
    }

    cout << ans;
    return 0;
}