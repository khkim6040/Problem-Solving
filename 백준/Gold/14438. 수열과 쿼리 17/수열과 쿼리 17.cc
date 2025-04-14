#include <iostream>

#define INF 2111111111

using namespace std;

int t[400004];

int N, M;

int find(int idx, int s, int e, int const l, int const r) {
    if(l>e || r<s) return INF;
    if(l<=s && e<=r) return t[idx];

    return min(find(idx*2, s, (s+e)/2, l, r), find(idx*2+1, (s+e)/2 + 1, e, l, r));
}

void update(int idx, int s, int e, int const arr_idx, int const val) {
    if(s==e) {
        t[idx] = val;
        return;
    }

    int mid = (s+e)/2;
    if(arr_idx <= mid) {
        update(idx*2, s, mid, arr_idx, val);
    } else {
        update(idx*2+1, mid+1, e, arr_idx, val);
    }
    t[idx] = min(t[idx*2], t[idx*2+1]);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    fill_n(&t[0], 4*N, INF);
    for(int i=1; i<=N; i++) {
        int x;
        cin >> x;
        update(1, 1, N, i, x);
    }

    cin >> M;

    for(int i=0; i<M; i++) {
        int cmd;
        cin >> cmd;
        
        if(cmd==1) {
            int i, v;
            cin >> i >> v;
            update(1, 1, N, i, v);
        } else {
            int i, j;
            cin >> i >> j;
            cout << find(1, 1, N, i, j) << '\n';
        }
    }

    return 0;
}