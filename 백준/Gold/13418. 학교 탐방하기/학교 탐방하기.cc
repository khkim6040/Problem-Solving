#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DSU {
    vector<int> parent, rank, size;
    DSU(int n) : parent(n), rank(n), size(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int u) {
        if (u == parent[u])
            return u;
        else
            return parent[u] = find(parent[u]);
    }
    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (rank[u] > rank[v]) swap(u, v); // rank가 높은 쪽으로 합친다
        parent[u] = v;
        size[v] += size[u];
        if (rank[u] == rank[v]) rank[v] += 1;
    }
};

struct Node {
    int s;
    int e;
    int cost;

    bool operator< (const Node& other) const {
        return cost < other.cost;
    }
};

int N, M;
// vector<vector<Node>> g;
vector<Node> edges;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    // g.assign(N+1, vector<Node>());
    for(int i=0; i<=M; i++) {
        int s, e, c;
        cin >> s >> e >> c;

        // g[s].push_back({e, c});
        // g[e].push_back({s, c});
        edges.push_back({s, e, c});
    }

    sort(edges.begin(), edges.end());

    // MAX
    int ans = 0;
    int edge_cnt = 0;
    int asc_cnt = 0;
    DSU max_d(N+1);
    for(auto edge: edges) {
        auto [s, e, cost] = edge;
        // cout << s << ' ' << e << ' ' << cost << '\n';

        if(max_d.find(s) != max_d.find(e)) {
            max_d.merge(s, e);
            edge_cnt++;
            if(cost==0) {
                asc_cnt++;
            }
        }

        if(edge_cnt == N) break;
    }
    // cout << asc_cnt << '\n';

    ans += asc_cnt*asc_cnt;

    // MIN
    reverse(edges.begin(), edges.end());
    
    edge_cnt = 0;
    asc_cnt = 0;
    DSU min_d(N+1);
    for(auto edge: edges) {
        auto [s, e, cost] = edge;
        // cout << s << ' ' << e << ' ' << cost << '\n';
        if(min_d.find(s) != min_d.find(e)) {
            min_d.merge(s, e);
            edge_cnt++;
            if(cost==0) {
                asc_cnt++;
            }
        }

        if(edge_cnt == N) break;
    }
    // cout << asc_cnt << '\n';

    ans -= asc_cnt*asc_cnt;

    cout << ans;
    return 0;
}