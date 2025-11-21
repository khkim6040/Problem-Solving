#include <iostream>
#include <vector>
#include <unordered_map>

#define R 1
#define W 2
using namespace std;

int K, V, E;
bool visited[20005];
int d[20005];
vector<vector<int>> g;

// 홀수 사이클이면 true 반환
bool dfs(int cur, int prev) {
    visited[cur] = true;
    d[cur] = d[prev] == R ? W : R;

    bool cycle = false;
    unordered_map<int, bool> m;
    for(int next: g[cur]) {
        if(next == prev) continue;
        if(m[next]) continue;
        if(visited[next]) {
            if(d[cur] == d[next]) {
                cycle = true;
            }
            continue;
        }
        m[next] = true;
        cycle = max(cycle, dfs(next, cur));
    }

    return cycle;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K;

    while(K--) {
        cin >> V >> E;
        fill_n(&visited[0], 20005, false);
        fill_n(&d[0], 20005, 0);
        g.assign(V+1, vector<int>());
        for(int i=0; i<E; i++) {
            int s, e;
            cin >> s >> e;
            g[s].push_back(e);
            g[e].push_back(s);
        }

        bool flag = true;
        for(int i=1; i<=V; i++) {
            if(visited[i]) continue;
            if(dfs(i, 0)) {
                flag = false;
                break;
            }
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}