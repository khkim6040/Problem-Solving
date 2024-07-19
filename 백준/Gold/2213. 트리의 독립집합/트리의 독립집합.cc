#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define pii pair<int, int>

int N;
vector<int> b;
vector<vector<int>> g;
vector<vector<int>> dp;
vector<vector<vector<int>>> dp_nodes;

void dfs(int cur, int parent) {
    dp[cur][1] = b[cur];
    dp_nodes[cur][1].push_back(cur);

    for (auto chld : g[cur]) {
        if (chld == parent) continue;
        dfs(chld, cur);
        int max_idx = dp[chld][0] > dp[chld][1] ? 0 : 1;
        dp[cur][0] += dp[chld][max_idx];
        dp_nodes[cur][0].insert(dp_nodes[cur][0].end(), dp_nodes[chld][max_idx].begin(), dp_nodes[chld][max_idx].end());
        dp[cur][1] += dp[chld][0];
        dp_nodes[cur][1].insert(dp_nodes[cur][1].end(), dp_nodes[chld][0].begin(), dp_nodes[chld][0].end());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    b.resize(N + 1);
    g.resize(N + 1, vector<int>(0));
    dp.resize(N + 1, vector<int>(2));
    dp_nodes.resize(N + 1, vector<vector<int>>(2, vector<int>(0)));

    for (int i = 1; i <= N; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int s, e;
        cin >> s >> e;
        g[s].push_back(e);
        g[e].push_back(s);
    }

    dfs(1, -1);

    int max_idx = dp[1][0] > dp[1][1] ? 0 : 1;
    sort(dp_nodes[1][max_idx].begin(), dp_nodes[1][max_idx].end());
    cout << dp[1][max_idx] << '\n';
    for (auto e : dp_nodes[1][max_idx]) {
        cout << e << ' ';
    }

    return 0;
}
