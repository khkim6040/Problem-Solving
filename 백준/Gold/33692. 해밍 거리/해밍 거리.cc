#include <cmath>
#include <iostream>

#define ll long long

using namespace std;

ll A, B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B;

    ll v = 2;
    int cnt = 0;
    while (B >= v) {
        v *= 2;
        cnt++;
    }

    ll ansA = 0;
    ll ansB = 0;
    int ans = 0;

    ll AA = A;
    ll BB = B;

    bool has_A_minus = false;
    for (int i = cnt; i >= 0; i--) {
        ll v = pow(2, i);
        // cout << v << '\n';
        int f1 = AA >= v ? 1 : 0;
        int f2 = BB >= v ? 1 : 0;
        if (f1)
            AA -= v;
        if (f2)
            BB -= v;

        if (i == cnt) {
            if (f1) {
                ansA += v;
                ansB += v;
                has_A_minus = true;
            } else {
                ansB += v;
            }
            continue;
        }

        if (f1) {
            if (f2) {
                if (B - v > A) {
                    has_A_minus = true;
                    ansA += v;
                } else {
                    ansA += v;
                    ansB += v;
                }
            } else {
                has_A_minus = true;
                ansA += v;
            }
        } else {
            if (f2) {
                ansB += v;
            } else {
                if (B > A + v) {
                    ansA += v;
                }
            }
        }
    }

    cout << ansA << ' ' << ansB;

    return 0;
}