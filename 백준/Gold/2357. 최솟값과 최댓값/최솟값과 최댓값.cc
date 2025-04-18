#include <iostream>
#include <vector>

#define INF 2111111111
#define NINF -2111111111
#define pii pair<int, int>

using namespace std;


pii t[400004]; // <min, max>
int N, M;

void update(int node, int idx, int s, int e, int v) {
    if(s==e) {
        t[node] = {v, v};
        return;
    }

    int mid = (s+e)/2;

    if(idx>mid) {
        update(2*node+1, idx, mid+1, e, v);
    } else {
        update(2*node, idx, s, mid, v);
    }

    t[node].first = min(t[2*node].first, t[2*node+1].first);
    t[node].second = max(t[2*node].second, t[2*node+1].second);
 }

 pii find(int node, int s, int e, int l, int r) {
    if(l > e || r < s) {
        return {INF, NINF};
    }

    if(l<=s && e<=r) {
        return t[node];
    }

    int mid = (s+e)/2;

    pii res1 = find(2*node, s, mid, l, r);
    pii res2 = find(2*node+1, mid+1, e, l, r);

    return {min(res1.first, res2.first), max(res1.second, res2.second)};
 }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i=1; i<=N; i++) {
        int x;
        cin >> x;

        update(1, i, 1, N, x);
    }

    while(M--) {
        int l, r;
        cin >> l >> r;

        pii res = find(1, 1, N, l, r);
        cout << res.first << ' ' << res.second << '\n';
    }

    return 0;
}