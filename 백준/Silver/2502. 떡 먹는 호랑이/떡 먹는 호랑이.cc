#include <iostream>
using namespace std;
typedef long long ll;
#define pii pair<ll, int>

int D, K;
pair<ll, ll> fibo[35];  // {a, b}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> D >> K;
    fibo[0] = {1, 0};
    fibo[1] = {0, 1};
    for (int i = 2; i <= 30; i++) {
        fibo[i] = {fibo[i - 1].first + fibo[i - 2].first, fibo[i - 1].second + fibo[i - 2].second};
    }

    ll A = 1;
    ll B;
    auto [q_A, q_B] = fibo[D - 1];
    // cout << q_A << ' ' << q_B << '\n';
    while (A <= 100000) {
        bool int_check = (K - q_A * A) % q_B == 0;
        if (int_check) {
            B = (K - q_A * A) / q_B;
            break;
        }
        A++;
    }

    cout << A << '\n'
         << B;
    return 0;
}
