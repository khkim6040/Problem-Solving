#include <iostream>

using namespace std;

int N;
int buy[16][16];
int dp[1<<16][16];
int ans = 1;

int dfs(int status, int cur, int cost) {
    int cur_status = status | (1<<cur);
    if(dp[cur_status][cur]) {
        return dp[cur_status][cur];
    }

    int len = 0;
    for(int i=1; i<N; i++) {
        if(cost > buy[cur][i] || (cur_status & (1<<i)) || i == cur) continue;
        len = max(len, dfs(cur_status | (1<<cur), i, buy[cur][i])+1); 
    }

    // cout << cur_status << ' ' << cur << ' ' << cost << ' ' << len << '\n';

    return dp[cur_status][cur] = len;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            char c;
            cin >> c;
            buy[i][j] = c - '0';
        }
    }

    

    cout << dfs(0, 0, 0)+1;

    return 0;
}

// 32 16 8 4 2 1