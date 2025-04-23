#include <iostream>

#define ll long long
using namespace std;

int N, Q;
ll t[400004];

void update(int node, int s, int e, int idx, ll v) {
    if(s==e) {
        t[node] = v;
        return;
    }

    int mid = (s+e)/2;
    if(idx <= mid) {
        update(node*2, s, mid, idx, v);
    } else {
        update(node*2+1, mid+1, e, idx, v);
    }

    t[node] = t[node*2] + t[node*2+1];
}

ll find(int node, int s, int e, int l, int r) {
    if(l>e || r<s) {
        return 0;
    }

    if(l<=s && e<=r) {
        return t[node];
    }

    int mid = (s+e)/2;
    return find(node*2, s, mid, l, r) + find(node*2+1, mid+1, e, l, r);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> Q;

    for(int i=1; i<=N; i++) {
        int x;
        cin >> x;
        update(1, 1, N, i, x);
    }

    while(Q--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if(x>y) {
            swap(x, y);
        }
        cout << find(1, 1, N, x, y) << '\n';
        update(1, 1, N, a, b);
    }



    return 0;
}