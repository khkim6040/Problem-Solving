#include <iostream>
#include <algorithm>
using namespace std;
#define INF 122222222

int N, K;
int energy[25][2];
int dp[25][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i=1; i<N; i++) {
        cin >> energy[i][0] >> energy[i][1];
    }
    cin >> K;

    dp[1][0] = 0;
    dp[2][0] = dp[1][0] + energy[1][0];
    dp[2][1] = INF;
    dp[3][0] = min(dp[1][0] + energy[1][1], dp[2][0] + energy[2][0]);
    dp[3][1] = dp[1][0] + energy[1][1];

    for(int i=4; i<=N; i++) {
        dp[i][0] = min({dp[i-1][0] + energy[i-1][0], dp[i-2][0] + energy[i-2][1]});
        dp[i][1] = min({dp[i-1][1] + energy[i-1][0], dp[i-2][1] + energy[i-2][1], dp[i-3][0] + K});
    }
    
    cout << min(dp[N][0], dp[N][1]);
    return 0;
}