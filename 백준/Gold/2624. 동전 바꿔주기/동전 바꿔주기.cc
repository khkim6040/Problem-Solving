#include <iostream>
#include <vector>
using namespace std;

struct Coin{
    int value;
    int count;
};

int T, K;
vector<Coin> coins;
int dp[10006];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> T >> K;
    for(int i=0; i<K; i++) {
        int v, c;
        cin >> v >> c;
        coins.push_back({v, c});
    }

    dp[0] = 1;
    for(Coin coin: coins) {
        for(int i=T; i>=0; i--) {
            for(int j=1; j<=coin.count; j++) {
                if(i-coin.value*j < 0) break;
                dp[i] += dp[i-coin.value*j];
            }
        }
    }

    cout << dp[T];
    return 0;
}