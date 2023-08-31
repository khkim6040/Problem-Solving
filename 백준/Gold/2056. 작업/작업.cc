#include <iostream>
using namespace std;

int N;
int dp[10005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    int answer = 0;
    for(int i=1; i<=N; i++) {
        int cost, required_num;
        cin >> cost >> required_num;
        while(required_num--) {
            int required_task;
            cin >> required_task;
            dp[i] = max(dp[i], dp[required_task]);
        }
        dp[i] += cost;
        answer = max(answer, dp[i]);
    }

    cout << answer;
    return 0;
}