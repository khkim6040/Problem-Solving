#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int N, L;
int b[555];
int dp[555];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i=1; i<=N; i++) {
        int s, e;
        cin >> s >> e;
        b[s] = e;
    }

    int ans = 0;
    for(int i=1; i<=500; i++) {
        if(b[i]==0) continue;
        dp[i] = 1;
        for(int j=1; j<i; j++) {
            if(b[j]==0) continue;
            if(b[j] >= b[i]) continue;
            dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);
    }

    cout << N - ans;
    
    return 0;
}
