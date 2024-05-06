#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll T, N;
ll a, b, c, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N;
        vector<vector<ll>> board;
        board.assign(3, vector<ll>(N + 1));
        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> board[i][j];
            }
        }

        cin >> a >> b >> c >> d;

        // for (int i = 1; i <= 2; i++) {
        //     for (int j = 1; j <= N; j++) {
        //         cout << board[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        if (a > c) {
            ll tmp1 = a;
            ll tmp2 = b;
            a = c;
            b = d;
            c = tmp1;
            d = tmp2;
        }
        // left
        ll sum = a == c ? 0 : board[!(b - 1) + 1][a];
        ll left_max = max(1LL * 0, sum);
        for (int i = a - 1; i >= 1; i--) {
            ll aa = board[1][i];
            ll bb = board[2][i];
            ll cc = aa + bb;
            ll tmp = max({aa, bb, cc});
            left_max = max(left_max, tmp + sum);
            sum += cc;
        }
        // cout << left_max << ' ';

        // right
        sum = a == c ? 0 : board[!(d - 1) + 1][c];
        ll right_max = max(1LL * 0, sum);
        for (int i = c + 1; i <= N; i++) {
            ll aa = board[1][i];
            ll bb = board[2][i];
            ll cc = aa + bb;
            ll tmp = max({aa, bb, cc});
            right_max = max(right_max, tmp + sum);
            sum += cc;
        }
        // cout << right_max << ' ';

        // middle
        ll middle_max = 0;
        for (int i = a + 1; i < c; i++) {
            ll aa = board[1][i];
            ll bb = board[2][i];
            ll cc = aa + bb;
            ll tmp = max({aa, bb, cc});
            middle_max += tmp;
        }
        // cout << middle_max << ' ';
        ll ans;
        if (a == c) {
            ans = max(left_max, right_max);
            ans += board[b][a] + board[d][c];
        } else {
            ans = left_max + right_max + middle_max + board[b][a] + board[d][c];
        }
        cout << ans << ' ';
    }

    return 0;
}