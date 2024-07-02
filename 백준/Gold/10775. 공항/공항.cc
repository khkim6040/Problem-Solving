#include <iostream>
#include <vector>
using namespace std;

int G, P, ans;

struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n) {
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
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
        if (u < v) swap(u, v);
        parent[u] = v;
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> G >> P;
    DSU d(G + 1);

    for (int i = 0; i < P; i++) {
        int g;
        cin >> g;
        if (d.find(g) == 0) break;
        d.merge(g, d.find(g) - 1);
        ans++;
    }

    cout << ans;

    return 0;
}