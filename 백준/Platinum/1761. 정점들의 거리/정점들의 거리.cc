#include <cmath>
#include <iostream>
#include <vector>
#define MAXNODE 40005
#define MAXLEVEL 20  // log40000 < 20
using namespace std;

struct Node {
    int index;
    int dist;
};

int N, M;
int dist_from_root[MAXNODE];
int depth[MAXNODE];
int parent[MAXNODE][MAXLEVEL];
vector<vector<Node>> tree;

// 모든 정점의 깊이와 루트로부터의 거리 구하기
// 바로 위인 2^0번째 조상도 작성한다
void dfs(int parent_, int cur, int depth_, int dist) {
    depth[cur] = depth_;
    dist_from_root[cur] = dist_from_root[parent_] + dist;
    for (Node next : tree[cur]) {
        if (next.index == parent_)
            continue;
        parent[next.index][0] = cur;
        dfs(cur, next.index, depth_ + 1, next.dist);
    }
}

int find_max_level(int index) {
    return floor(log(depth[index]) / log(2));
}

// b의 깊이가 더 깊다고 가정
int find_LCA(int a_, int b_) {
    int a = a_;
    int b = b_;
    // 깊이 같게 하기
    int max_level = find_max_level(b);
    for (int i = max_level; i >= 0; i--) {
        if (depth[a] <= depth[parent[b][i]])
            b = parent[b][i];
    }
    if (a == b) {
        return a;
    }
    // 최소 공통 조상 찾기
    int lca;
    for (int i = max_level; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
        lca = parent[a][i];
    }

    return lca;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    tree.assign(N + 1, vector<Node>());

    for (int i = 0; i < N - 1; i++) {
        int start, end, dist;
        cin >> start >> end >> dist;
        tree[start].push_back({end, dist});
        tree[end].push_back({start, dist});
    }
    // 1번째 노드를 루트 노드로 설정
    dfs(0, 1, 0, 0);
    // parent 배열 작성
    for (int i = 1; i < MAXLEVEL; i++) {
        for (int j = 1; j <= N; j++) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
    // 쿼리 처리
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        // b의 깊이를 더 깊게 설정
        if (depth[a] > depth[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        int lca = find_LCA(a, b);
        // cout << lca << ' ';
        cout << dist_from_root[a] + dist_from_root[b] - 2 * dist_from_root[lca] << '\n';
    }
    return 0;
}