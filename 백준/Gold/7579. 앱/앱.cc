#include <iostream>
#include <vector>
#define MAX 2111111111
using namespace std;

int N, M;
int memory[105];
int cost[105];
int dp[105][10005]; // i개 고려했을 떄 cost = j인 경우에 최대 메모리

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        cin >> memory[i];
    }
    for(int i=1; i<=N; i++) {
        cin >> cost[i];
    }    
    // dp
    for(int i=1; i<=N; i++) {
        for(int j=0; j<=10000; j++) {
            if(cost[i] > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]]+memory[i]);
            }
        }
    }
    
    for(int i=0; i<=10000; i++) {
        if(dp[N][i] >= M) {
            cout << i;
            break;
        }
    }
    return 0;
}