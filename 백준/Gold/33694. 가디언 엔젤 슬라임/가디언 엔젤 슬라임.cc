#include <cmath>
#include <iostream>
#include <map>
#include <queue>

#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll A, B, C, T;
ll N, X;

priority_queue<pll, vector<pll>, greater<pll>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> A >> B >> C >> T;

        ll f = X % A == 0 ? 0 : 1;
        ll t1 = X / A + f;

        ll ff = C % A == 0 ? 0 : 1;
        ll t3 = C / A + ff;
        // cout << t3 << '\n';
        ll t2 = (A * t3 - X) / B + 1;
        // cout << T + t3 + t2 << '\n';

        // cout << T + t1 << ' ' << T + t1 + t2 - 1 << '\n';
        if (t3 < t1) continue;
        pq.push({T + t1, 0});
        pq.push({T + t3 + t2, 1});

        // for (int i = T + t1; i < T + t3 + t2; i++) {
        //     m[i]++;
        // }
    }

    ll cur_v = 0;
    ll cnt = 0;
    ll ans = 0;

    while (!pq.empty()) {
        pll cur = pq.top();
        pq.pop();

        // cout << cur.first << ' ' << cur.second << '\n';

        ll v = cur.first;
        bool is_open = !cur.second;

        if (cnt >= 3) {
            ans += v - cur_v;
        }

        if (is_open) {
            cur_v = v;
            cnt++;
        } else {
            cur_v = v;
            cnt--;
        }
    }

    cout << ans;

    return 0;
}