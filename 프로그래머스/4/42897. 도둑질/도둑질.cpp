#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1000005][2][2]; // dp[i][j][k], k는 지금까지 0번째 집을 털었는지 안 털었는지 정보 저장(마지막을 위해)
// dp[i][0] i번째 집까지 고려했을 때, i번째 집을 털지 않을 때 최댓값
// dp[i][1] i번째 집까지 고려했을 때, i번째 집을 털었을 때 최댓값

int solution(vector<int> money) {
    int answer = 0;
    
    int size = money.size();
    dp[0][0][0] = 0;
    dp[0][1][1] = money[0];
    
    dp[1][0][0] = 0;
    dp[1][0][1] = dp[0][1][1];
    dp[1][1][0] = money[1];
    dp[1][1][1] = 0; // 불가능
    for(int i=2; i<size-1; i++) {
        dp[i][0][0] = max(dp[i-1][0][0], dp[i-1][1][0]);
        dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][1]);
        
        dp[i][1][0] = dp[i-1][0][0] + money[i];
        dp[i][1][1] = dp[i-1][0][1] + money[i];
    }
    
    // 마지막 집 고려
    dp[size-1][0][0] = max(dp[size-2][0][0], dp[size-2][1][0]);
    dp[size-1][0][1] = max(dp[size-2][0][1], dp[size-2][1][1]);
    
    dp[size-1][1][0] = dp[size-2][0][0] + money[size-1];

    answer = max({dp[size-1][0][0], dp[size-1][0][1], dp[size-1][1][0], dp[size-1][1][1]});
    return answer;
}