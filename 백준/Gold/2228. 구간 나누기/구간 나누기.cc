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

    for(int i=0; i<N; i++) {
        cin >> b[i];
        if(i==0) pref_sum[i] = b[i];
        else pref_sum[i] = pref_sum[i-1] + b[i];
    }

    fill_n(&dp[0][0], 111*55, -111111111);
    dp[0][1] = b[0];
    for(int i=1; i<N; i++) {
        dp[i][1] = max(dp[i-1][1], pref_sum[i]);
        for(int j=i; j>0; j--) {
            dp[i][1] = max(dp[i][1], pref_sum[i]-pref_sum[j-1]);
        }
    }

    for(int k=2; k<=M; k++) {
        for(int i=2; i<N; i++) {
            dp[i][k] = dp[i-1][k];
            for(int j=i; j-2>=0; j--) {
                dp[i][k] = max(dp[i][k], dp[j-2][k-1]+pref_sum[i]-pref_sum[j-1]);
            }
        }
    }

    cout << dp[N-1][M];

    return 0;
}