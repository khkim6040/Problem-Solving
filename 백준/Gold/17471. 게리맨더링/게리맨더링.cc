#include <iostream>
#include <vector>
#include <cmath>

#define RED 0
#define BLUE 1

using namespace std;

int N;
vector<vector<int>> g;
int pop[15];
bool visited[15];

int get_diff(int state) {
    int r = 0;
    int b = 0;
    for(int i=1; i<=N; i++) {
        int p = state & 1;
        if(p == BLUE) b += pop[i];
        else r += pop[i];
        state /= 2;
    }

    return abs(r-b);
}

void dfs(const int state, int cur) {
    int curp = (state & (1<<(cur-1))) > 0;
    for(int next: g[cur]) {
        int nextp = (state & (1<<(next-1))) > 0;
        if(visited[next] || nextp != curp) continue;
        visited[next] = true;
        dfs(state, next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> pop[i];
    }

    g.assign(N+1, vector<int>());
    for(int i=1; i<=N; i++) {
        int m;
        cin >> m;
        for(int j=0; j<m; j++) {
            int e;
            cin >> e;
            g[i].push_back({e});
        }
    }

    int INF = 211111111;
    int ans = INF;
    for(int state=0; state<pow(2,N); state++) {
        fill_n(&visited[0], 15, false);

        int cnt = 0;
        for(int i=1; i<=N; i++) {
            if(visited[i]) continue;
            visited[i] = true;
            dfs(state, i);
            cnt++;
        }

        if(cnt!=2) continue;
        ans = min(ans, get_diff(state));
    }

    cout << (ans==INF ? -1 : ans);

    return 0;
}