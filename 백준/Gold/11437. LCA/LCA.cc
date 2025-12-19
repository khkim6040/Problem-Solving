#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> g;
int root[50005];
int depth[50005];

void fill_root(int r, int cur, int d) {
    root[cur] = r;
    depth[cur] = d;

    int size = g[cur].size();

    for(int next: g[cur]) {
        if(root[next] != 0) continue;
        fill_root(cur, next, d+1);
    }
}

int find_root(int a, int b) {
    while(a != b) {
        // cout << a << ' ' << b << '\n';
        if(depth[a] > depth[b]) {
            a = root[a];
        } else if(depth[a] < depth[b]) {
            b = root[b];
        } else {
            a = root[a];
            b = root[b];
        }
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    g.assign(N+1, vector<int>());

    for(int i=0; i<N-1; i++) {
        int s, e;
        cin >> s >> e;
        g[s].push_back(e);
        g[e].push_back(s);
    }

    root[1] = 1;
    depth[1] = 0;
    for(int next: g[1]) {
        fill_root(1, next, 1);
    }

    cin >> M;    
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        cout << find_root(a, b) << '\n';
    }
     
    return 0;
}