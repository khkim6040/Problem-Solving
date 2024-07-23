#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define INF 2111111111

int N;
int b[20][20];
int dp[20][1 << 20];

inline int count_1(int state) {
    int cnt = 0;
    while (state) {
        cnt += (state & 1);
        state >>= 1;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> b[i][j];
        }
    }

    for (int state = 1; state < (1 << N); state++) {
        int cur = count_1(state) - 1;  // current worker
        // cout << state << ' ' << cur << '\n';
        dp[cur][state] = INF;
        for (int job = 0; job < N; job++) {
            if (!(state & (1 << job))) continue;
            if (cur == 0) {
                dp[cur][state] = b[cur][job];
            } else {
                dp[cur][state] = min(dp[cur][state], dp[cur - 1][state & ~(1 << job)] + b[cur][job]);
            }
        }
        // cout << dp[cur][state] << '\n';
    }

    cout << dp[N - 1][(1 << N) - 1];

    return 0;
}
