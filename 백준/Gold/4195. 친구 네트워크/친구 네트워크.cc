#include <iostream>
#include <map>
#include <string>
#include <vector>
typedef long long ll;
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
        if (rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        size[v] += size[u];
        if (rank[u] == rank[v]) rank[v] += 1;
    }
};

int T;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        int size = 0;
        map<string, int> m;
        int F;
        cin >> F;
        DSU d(2 * F);
        while (F--) {
            string s, e;
            cin >> s >> e;
            if (m.find(s) == m.end()) {
                m.insert({s, size});
                size++;
            }
            if (m.find(e) == m.end()) {
                m.insert({e, size});
                size++;
            }

            int si, ei;
            si = m[s];
            ei = m[e];
            d.merge(si, ei);

            cout << d.size[d.find(si)] << '\n';
        }
    }

    return 0;
}