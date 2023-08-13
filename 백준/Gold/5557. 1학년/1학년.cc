#include <iostream>
using namespace std;

int N;
int nums[105];
long long dp[105][21];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> nums[i];
    }

    dp[1][nums[1]] = 1;
    for(int i=2; i<N; i++) {
        for(int j=0; j<=20; j++) {
            if(j-nums[i] >= 0) {
                dp[i][j] += dp[i-1][j-nums[i]];
            }
            if(j+nums[i] <= 20) {
                dp[i][j] += dp[i-1][j+nums[i]];
            }
        }
    }

    int target = nums[N];
    cout << dp[N-1][target];

    return 0;
}