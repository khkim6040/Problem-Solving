#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll N, K;
vector<ll> A;

ll neededCandy(ll score) {
    ll res = 0;
    for (auto x : A) {
        if (x == 0) continue;
        if (x < score) {
            break;
        }
        res += x - score;
    }
    return res;
}

ll solve(ll low, ll high) {
    while (low <= high) {
        if (low == high) {
            return low;
        }
        ll mid = (low + high) / 2;
        ll needed_candy = neededCandy(mid);
        // cout << mid << ' ' << needed_candy << '\n';
        if (needed_candy < K) {
            high = mid;
        } else if (needed_candy > K) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    A.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    A.push_back(0);
    sort(A.rbegin(), A.rend());

    cout << solve(A[N], A[0]);

    return 0;
}