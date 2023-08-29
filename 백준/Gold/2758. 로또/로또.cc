#include <iostream>
using namespace std;

int T, N, M;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> T;
    long long int dp[2002][12] = {0, };
    for(int i=1; i<=2000; i++) {
        dp[i][1] = 1;
        for(int j=1; j<=i/2; j++) {
            for(int k=1; k<10; k++) {
                dp[i][k+1] += dp[j][k];
            }
        }
    }

    while(T--) {
        cin >> N >> M;
        long long int answer = 0;
        for(int i=1; i<=M; i++) {
            answer += dp[i][N];
        }
        cout << answer << '\n';
    }
    return 0;
}