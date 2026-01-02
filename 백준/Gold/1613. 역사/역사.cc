#include <iostream>
#include <vector>
#include <unordered_set>

#define ll long long
#define pll pair<ll, ll>
using namespace std;

vector<unordered_set<int>> childs;
vector<vector<int>> g;
bool is_child[404];
int N, K, S;
bool visited[404];

unordered_set<int> dfs(int cur) {
    if(visited[cur]) return childs[cur];
    visited[cur] = true;

    for(int next: g[cur]) {
        unordered_set<int> ret = dfs(next);
        childs[cur].insert(ret.begin(), ret.end());
        childs[cur].insert(next);
    }

    return childs[cur];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    childs.assign(N+1, unordered_set<int>());
    g.assign(N+1, vector<int>());

    for(int i=0; i<K; i++) {
        int s, e;
        cin >> s >> e;
        g[s].push_back(e);
        is_child[e] = true;
    }

    for(int i=1; i<=N; i++) {
        if(is_child[i]) continue;
        dfs(i);
    }

    cin >> S;
    for(int i=0; i<S; i++) {
        int a, b;
        cin >> a >> b;
        int ans;
        if(childs[a].find(b) != childs[a].end()) ans = -1;
        else if(childs[b].find(a) != childs[b].end()) ans = 1;
        else ans = 0;

        cout << ans << '\n';
    }

   

    return 0;
}