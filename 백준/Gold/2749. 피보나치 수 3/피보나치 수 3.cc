#include <iostream>
#include <vector>

#define ll long long
#define vvll vector<vector<long long>>
#define MOD 1000000

using namespace std;

ll N;
vvll const BASIC = {{0, 1}, {1, 1}};
// void print_mat(vvll v) {
//     cout << v[0][0] << ' ' << v[0][1] << '\n';
//     cout << v[1][0] << ' ' << v[1][1] << '\n';
// }
ll sum_(vvll m) { return (m[0][1] + m[1][1]) % MOD; }

vvll mat_mul(vvll mat, bool is_odd) {
    vvll ret = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ret[i][j] += (mat[i][k] * mat[k][j]) % MOD;
            }
        }
    }

    if (is_odd) {
        vvll const temp = ret;
        ret = vvll{{0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    ret[i][j] += (temp[i][k] * BASIC[k][j]) % MOD;
                }
            }
        }
    }

    return ret;
}

vvll get_mat(ll n) {
    if (n == 1) {
        return BASIC;
    }

    return mat_mul(get_mat(n / 2), n % 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    if (N == 0 || N == 1) {
        cout << N;
        return 0;
    }

    if (N == 2) {
        cout << 1;
        return 0;
    }

    cout << sum_(get_mat(N - 2));

    return 0;
}