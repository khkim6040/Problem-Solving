#include <iostream>
using namespace std;

int N;
int dp[205];
int students[205];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> students[i];
    }

    // LIS
    int max_count = 0;
    for(int i=1; i<=N; i++) {
        dp[i] = 1;
        for(int j=1; j<i; j++) {
            if(students[i] > students[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        max_count = max(max_count, dp[i]);
    }

    cout << N-max_count;
    return 0;
}