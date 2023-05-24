#include <iostream>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int N;
ll dp[1000005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    dp[1] = 2;
    dp[2] = 7;
    ll dp_sum = 9;
    for(int i=3; i<=1000000; i++) {
        dp[i] = (2+2*dp_sum+dp[i-2])%MOD;
        dp_sum = (dp_sum+dp[i])%MOD;
    }
    
    cin >> N;
    cout << dp[N];
    return 0;
}