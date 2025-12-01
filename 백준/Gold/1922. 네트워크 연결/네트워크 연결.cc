#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define pii pair<int, int>
using namespace std;

int N, M;
struct Node {
    int s, e, c;

    bool operator< (const Node& other) const {
        return c > other.c;
    }
};

int rank_[1005];
int find(int idx) {
    if(idx == rank_[idx]) return idx;

    return rank_[idx] = find(rank_[idx]);
}

void merge(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if(pa > pb) swap(pa, pb);

    rank_[pb] = pa;
}

bool visited[1005];
priority_queue<Node> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        rank_[i] = i;
    }

    for(int i=0; i<M; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        q.push({s, e, c});
    }

    int ans = 0;
    int cnt = N-1;
    while(cnt>0) {
        Node cur = q.top();
        q.pop();
        int s = cur.s;
        int e = cur.e;
        int c = cur.c;
        if(find(s) == find(e)) continue;
        // cout << s << ' ' << e << ' ' << c << '\n';
        merge(s, e);
        ans += c;
        cnt--;
    }

    cout << ans;
    
    return 0;
}