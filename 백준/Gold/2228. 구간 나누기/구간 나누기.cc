#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int N, M;
int b[111];
int dp[111][55]; // dp[i][k] = 0부터 i까지 범위에서 k개의 구간을 선택했을 때 구간 합의 최댓값
int pref_sum[111];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    pref_sum[0] = 0;
    for(int i=1; i<=N; i++) {
        cin >> pref_sum[i];
        pref_sum[i] += pref_sum[i-1];
    }

    fill_n(&dp[0][0], 111*55, -111111111);
    dp[1][1] = pref_sum[1];
    for(int i=2; i<=N; i++) {
        dp[i][1] = dp[i-1][1];
        for(int j=i-1; j>=0; j--) {
            dp[i][1] = max(dp[i][1], pref_sum[i]-pref_sum[j]);
        }
    }

    for(int k=2; k<=M; k++) {
        for(int i=3; i<=N; i++) {
            dp[i][k] = dp[i-1][k];
            for(int j=i-1; j-1>=1; j--) {
                dp[i][k] = max(dp[i][k], dp[j-1][k-1]+pref_sum[i]-pref_sum[j]);
            }
        }
    }

    cout << dp[N][M];

    return 0;
}