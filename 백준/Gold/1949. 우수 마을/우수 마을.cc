#include <iostream>
#include <vector>

using namespace std;

int N;
int b[10005];
int dp[10005][2]; // dp[마을][우수마을 여부] = 해당 마을 children까지 고려했을 때 최대 우수마을 주민 수
vector<vector<int>> g;


void dfs(int cur, int parent) {
    dp[cur][1] = b[cur];

    for(int child: g[cur]) {
        if(child == parent) continue;
        dfs(child, cur);
        dp[cur][0] += max(dp[child][0], dp[child][1]);
        dp[cur][1] += dp[child][0];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    g.assign(N+1, vector<int>());
    for(int i=1; i<=N; i++) {
        cin >> b[i];
    }

    for(int i=1; i<=N-1; i++) {
        int s, e;
        cin >> s >> e;
        g[s].push_back(e);
        g[e].push_back(s);
    }

    dfs(1, -1);

    cout << max(dp[1][0], dp[1][1]);
    
    return 0;
}