#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1005][2]; //dp[i][0] = i번째까지 봤을 때 오름차순 최대 길이, dp[i][1] = i번째까지 내림차순
int A[1005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    int answer = 1;
    for(int i=0; i<N; i++) {
        dp[i][0] = 1;
        dp[i][1] = 1;
        for(int j=0; j<i; j++) {
            if(A[j] == A[i]) continue;
            else if(A[j] < A[i]) {
                dp[i][0] = max(dp[i][0], dp[j][0]+1);
            }
            else {
                dp[i][1] = max({dp[i][1], dp[j][0]+1, dp[j][1]+1});
            }
        }
        answer = max({answer, dp[i][0], dp[i][1]});
    }

    cout << answer;
    return 0;
}