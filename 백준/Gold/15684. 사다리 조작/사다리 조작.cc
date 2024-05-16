#include <iostream>
using namespace std;

int N, M, H;
int b[13][33];

int ans = 4;

bool check() {
    for (int i = 1; i <= N; i++) {
        int pos = i;
        for (int j = 1; j <= H; j++) {
            if (b[pos][j]) {
                pos++;
            } else if (b[pos - 1][j]) {
                pos--;
            }
        }
        if (pos != i) {
            return false;
        }
    }

    return true;
}

void go(int cnt, int n, int h) {
    if (check()) {
        ans = min(ans, cnt);
        return;
    } else if (cnt == 3) {
        return;
    }

    for (int i = n; i <= N - 1; i++) {
        for (int j = 1; j <= H; j++) {
            if (b[i][j] || b[i - 1][j] || b[i + 1][j] || (i == n && j <= h)) {
                continue;
            }

            b[i][j] = 1;
            // if (cnt == 2) {
            //     cout << "1 to " << i << " " << j << '\n';
            // }
            go(cnt + 1, i, j);
            // if (cnt == 2) {
            //     cout << "0 to " << i << " " << j << '\n';
            // }
            b[i][j] = 0;
        }
    }
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int a, b_;
        cin >> a >> b_;
        b[b_][a] = 1;
    }

    // 사다리를 1, 1에도 놓기 위해 n = 1, h = 0에서 시작
    go(0, 1, 0);

    ans = ans == 4 ? -1 : ans;
    cout << ans;

    return 0;
}