#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int N, L;
int b[55555];
int sum[55555];
int dp[4][55555];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> b[i];
        sum[i] = sum[i-1]+b[i];
    }
    cin >> L;

    for(int i=L; i<=N; i++) {
        dp[1][i] = max(dp[1][i-1], sum[i]-sum[i-L]);
    }

    for(int j=2; j<=3; j++) {
        for(int i=L; i<=N; i++) {
            dp[j][i] = max(dp[j-1][i-L] + sum[i]-sum[i-L], dp[j][i-1]);
        }
    }    

    cout << dp[3][N];
    return 0;
}
