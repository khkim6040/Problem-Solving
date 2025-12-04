#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>
using namespace std;

struct cmp {
    bool operator() (const pii &a, const pii &b) {
        return a.second < b.second;
    }
};

vector<vector<pii>> g;
int max_flow[10005];
int N, M;
int S, E;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    g.assign(N+1, vector<pii>());
    for(int i=0; i<M; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        g[s].push_back({e, c});
        g[e].push_back({s, c});
    }

    cin >> S >> E;

    priority_queue<pii, vector<pii>, cmp> q;

    max_flow[S] = 2111111111;
    q.push({S, 2111111111});

    while(!q.empty()) {
        pii cur = q.top();
        q.pop();
        if(cur.first == E) break;
        for(pii next: g[cur.first]) {
            int idx = next.first;
            int limit = next.second;
            int possible = min(limit, max_flow[cur.first]);
            if(max_flow[idx] >= possible) continue;
            max_flow[idx] = possible;
            q.push({idx, possible});
        }

    }

    cout << max_flow[E];

    return 0;
}