#include <iostream>
using namespace std;
#define SIZE 55

int N, L;

int b[105][105];

bool go(int n, bool is_horiz) {
    int prev = is_horiz ? b[n][0] : b[0][n];
    int same_cnt = 1;
    int false_cnt = 0;
    for (int i = 1; i < N; i++) {
        int cur = is_horiz ? b[n][i] : b[i][n];
        if (cur == prev) {
            if (false_cnt > 0) {
                false_cnt--;
            } else {
                same_cnt++;
            }
        } else if (cur == prev + 1 && same_cnt >= L) {
            if (false_cnt > 0) {
                return false;
            }
            same_cnt = 1;
        } else if (cur == prev - 1) {
            if (false_cnt > 0) {
                return false;
            }
            false_cnt = L - 1;
            same_cnt = 0;
        } else {
            return false;
        }
        prev = cur;
    }

    if (false_cnt > 0) {
        return false;
    }

    // cout << n << ' ' << (is_horiz ? "가로" : "세로") << '\n';
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> b[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += go(i, true);
        ans += go(i, false);
    }

    cout << ans;
    return 0;
}