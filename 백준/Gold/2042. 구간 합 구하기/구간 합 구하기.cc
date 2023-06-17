#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int N, M, K;
vector<ll> arr;
vector<ll> tree;

ll make(int index, int start, int end) {
    if(start==end) {
        tree[index] = arr[start];
        return tree[index];
    }
    int mid = (start+end)/2;
    return tree[index] = make(2*index, start, mid) + make(2*index+1, mid+1, end);
}

void update(int index, int start, int end, const int &where, const ll &diff) {
    if(where<start || where>end) {
        return;
    }
    tree[index] += diff;
    if(start==end) 
        return;
    int mid = (start+end)/2;
    update(2*index, start, mid, where, diff);
    update(2*index+1, mid+1, end, where, diff);
}

ll sum(int index, int start, int end, const int &from, const int &to) {
    if(start>to || end<from) {
        return 0;
    }
    if(start>=from && end<=to) {
        return tree[index];
    }

    int mid = (start+end)/2;
    return sum(2*index, start, mid, from, to) + sum(2*index+1, mid+1, end, from, to);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;
    arr.assign(N+1, 0);
    tree.assign(4*N, 0);
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
    }

    make(1, 1, N);
    for(int i=0; i<M+K; i++) {
        int c, from;
        ll to;
        cin >> c >> from >> to;
        if(c==1) {
            update(1, 1, N, from, to-arr[from]);
            arr[from] = to; 
        }
        else {
            cout << sum(1, 1, N, from, to) << '\n';
        }
    }

    return 0;
}