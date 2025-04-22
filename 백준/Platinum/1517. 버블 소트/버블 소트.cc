// seg tree 숫자 채우기
// for i 1~N 
    // i번째로 작은 수와 원래 그 수가 있던 인덱스 파악
    // 해당 인덱스~N까지 find, find = 그 범위에 속해있는 수의 총 개수 반환 => 오른쪽에 자신보다 작은 값의 총 개수 = 스왑 횟수
    // 해당 인덱스에 대응하는 트리에다 1을 마킹함으로써 그 인덱스에 수가 들어와있다고 명시



#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

struct Node {
    ll v;
    ll idx;

    bool operator< (const Node& other) const {
        if(v==other.v) {
            return idx < other.idx;
        }
        return v < other.v;
    }
};

vector<Node> vec;

int N;
ll t[2000005]; 

void update(ll node, ll s, ll e, ll idx) {
    if(s==e) {
        t[node] = 1;
        return;
    }

    ll mid = (s+e)/2;

    if(idx <= mid) {
        update(node*2, s, mid, idx);
    } else {
        update(node*2+1, mid+1, e, idx);
    }

    t[node] = t[node*2] + t[node*2+1];
}

ll find(ll node, ll s, ll e, ll l, ll r) {
    if(l>e || r<s) {
        return 0;
    }
    if(l<=s && e<=r) {
        return t[node];
    }

    ll mid = (s+e)/2;
    return find(node*2, s, mid, l, r) + find(node*2+1, mid+1, e, l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i=1; i<=N; i++) {
        ll x;
        cin >> x;
        vec.push_back({x, i});
    }
    sort(vec.begin(), vec.end());



    ll ans = 0;
    for(int i=0; i<N; i++) {
        auto [v, idx] = vec[i];
        ans += find(1, 1, N, idx+1, N);
        update(1, 1, N, idx);
    }

    cout << ans;
    return 0;
}