#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;

int dp[44][122];

int solution(vector<vector<int>> info, int n, int m) {
    N = info.size();
    
    int sumA = 0;
    for(int i=1; i<=N; i++) {
        int a = info[i-1][0];
        sumA += a;
        int b = info[i-1][1];
        for(int j=0; j<=m; j++) {
            dp[i][j] = dp[i-1][j];
            if(j>b) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-b]+a);
            }
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }
    
    int answer = sumA - dp[N][m];
    return answer >= n ? -1 : answer;
}