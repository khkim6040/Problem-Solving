#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>
#define INF 111111111111111
using namespace std;

int N, M;

struct Node{
    int a, b;
    ll len;

    bool operator< (const Node &other) const {
        return len < other.len;
    }
};

vector<Node> v;
pll b[1005];
int parent[1005];

int find(int a) {
    if(a == parent[a]) return a;

    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if(a==b) return;
    if(a>b) swap(a, b);

    parent[b] = a;
}

ll get_dist(int idx1, int idx2) {
    ll x1 = b[idx1].first;
    ll y1 = b[idx1].second;
    ll x2 = b[idx2].first;
    ll y2 = b[idx2].second;

    return pow(1LL*abs(x1-x2), 2) + pow(1LL*abs(y1-y2), 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int i=1; i<=N; i++) {
        ll x, y;
        cin >> x >> y;
        b[i] = {x, y};
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(i==j) continue;
            v.push_back({i, j, get_dist(i, j)});
        }
    }

    sort(v.begin(), v.end());

    // for(Node ele: v) {
    //     cout << ele.a << ' ' << ele.b << ' ' << ele.len << '\n';
    // }

    for(int i=1; i<=N; i++) {
        parent[i] = i;
    }

    int cnt = 0;
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) continue;
        merge(pa, pb);
        cnt++;
    }

    double ans = 0;
    for(Node ele: v) {
        int a = ele.a;
        int b = ele.b;
        ll len = ele.len;

        int pa = find(a);
        int pb = find(b);
        if(pa == pb) continue;
        merge(pa, pb);
        cnt++;
        ans += sqrt(len);

        if(cnt == N-1) break;
    }

    cout << fixed << setprecision(2) << ans; 

    return 0;
}