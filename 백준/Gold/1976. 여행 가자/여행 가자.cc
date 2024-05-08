#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
typedef long long ll;
using namespace std;

int N, M;
struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
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
        if (rank[u] == rank[v]) rank[v] += 1;
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    DSU s(N + 1);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int connected;
            cin >> connected;
            if (connected) {
                // cout << i << j << '\n';
                s.merge(i, j);
            }
        }
    }

    if (M == 0) {
        cout << "YES";
        return 0;
    }

    int x;
    cin >> x;
    int parent = s.find(x);
    for (int i = 0; i < M - 1; i++) {
        cin >> x;
        if (s.find(x) != parent) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}