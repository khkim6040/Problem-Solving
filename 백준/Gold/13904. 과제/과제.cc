#include <iostream>
#include <algorithm>
#include <queue>

#define pii pair<int, int>
using namespace std;

int N;
vector<pii> v;
priority_queue<int, vector<int>, greater<int>> pq;

bool cmp(const pii &a, const pii &b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++) {
        int d, w;
        cin >> d >> w;
        v.push_back({d, w});
    }

    sort(v.begin(), v.end(), cmp);

    for(pii p: v) {
        int d = p.first;
        int w = p.second;

        if(pq.empty() || pq.size() < d || pq.top() < w) {
            pq.push(w);
            if(pq.size() > d) {
                pq.pop(); // 최대 한 개만 더 들어갈 수 있으므로 pop() 한 번만 해도 됨
            }
        }
    }

    int ans = 0;
    while(!pq.empty()) {
        // cout << pq.top() << ' ';
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    return 0;
}