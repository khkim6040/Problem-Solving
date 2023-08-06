#include <iostream>
using namespace std;

int N;
int boxes[1005];
int dp[1005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    int dp[1005];
    for(int i=0; i<N; i++) {
        cin >> boxes[i];
    }
    // LIS
    int answer = -1;
    for(int i=0; i<N; i++) {
        dp[i] = 1;
        for(int j=0; j<i; j++) {
            if(boxes[i]>boxes[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        answer = max(answer, dp[i]);
    }

    cout << answer;
    return 0;
}
