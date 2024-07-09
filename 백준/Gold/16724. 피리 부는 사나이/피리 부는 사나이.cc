#include <iostream>
#include <stack>
#include <vector>
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
    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (rank[u] > rank[v]) swap(u, v);  // rank가 높은 쪽으로 합친다
        parent[u] = v;
        size[v] += size[u];
        if (rank[u] == rank[v]) rank[v] += 1;
        return true;
    }
};

int N, M;
char b[1005][1005];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> b[i][j];
        }
    }

    DSU d(N * M);
    int ans = N * M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (b[i][j] == 'U') {
                if (d.merge(i * M + j, (i - 1) * M + j)) {
                    ans--;
                }
            } else if (b[i][j] == 'L') {
                if (d.merge(i * M + j, i * M + j - 1)) {
                    ans--;
                }
            } else if (b[i][j] == 'D') {
                if (d.merge(i * M + j, (i + 1) * M + j)) {
                    ans--;
                }
            } else if (b[i][j] == 'R') {
                if (d.merge(i * M + j, i * M + j + 1)) {
                    ans--;
                }
            }
        }
    }

    cout << ans;

    return 0;
}
