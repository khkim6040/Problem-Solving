#include <iostream>

#define MOD 1000000007
#define ll long long

using namespace std;

ll t[4000004];
int N, M, K;

void update(int node, int s, int e, int idx, int v) {
    if(s==e) {
        t[node] = v;
        return;
    }

    int mid = (s+e)/2;

    if(idx<=mid) {
        update(node*2, s, mid, idx, v);
    } else {
        update(node*2+1, mid+1, e, idx, v);
    }

    t[node] = t[node*2]*t[node*2+1]%MOD;
}

ll find(int node, int s, int e, int l, int r) {
    if(l>e || r<s) {
        return 1;
    }

    if(l<=s && e<=r) {
        return t[node];
    }

    int mid = (s+e)/2;
    return find(node*2, s, mid, l, r) * find(node*2+1, mid+1, e, l, r)%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for(int i=1; i<=N; i++) {
        int x;
        cin >> x;
        update(1, 1, N, i, x);
    }

    for(int i=0; i<M+K; i++) {
        int cmd;
        cin >> cmd;
        if(cmd == 1) {
            // update
            int idx, v;
            cin >> idx >> v;
            update(1, 1, N, idx, v);
        } else {
            // find
            int l, r;
            cin >> l >> r;
            cout << find(1, 1, N, l, r) << '\n';
        }  

    }

    return 0;
}