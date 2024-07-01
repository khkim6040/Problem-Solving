#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define MAX 10000000000000000

ll A, B;
vector<ll> N;

ll g(ll n) {
    ll ret = 0;
    while (n != 0) {
        ll i = 0;
        for (i; (1LL << (i + 1)) <= n; i++) {
            ret += N[i];
        }
        // cout << n << '\n';
        n -= (1LL << i);
        ret += n + 1;
    }
    // cout << ret << '\n';
    return ret;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    N.push_back(1);  // f(1) = 1
    ll sum = N[0];
    for (ll i = 2; i <= MAX; i *= 2) {
        // 2제곱수 구간 별 f 합계 저장
        N.push_back(sum + i);
        sum = 2 * sum + i;
    }
    cin >> A >> B;
    cout << g(B) - g(A - 1);
    return 0;
}