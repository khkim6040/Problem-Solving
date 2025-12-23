#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
using namespace std;

int N;
vector<pii> v;
int lectures[10005];

bool cmp(const pii &a, const pii &b) {
    if(a.second == b.second) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int i=0; i<N; i++) {
        int p, d;
        cin >> p >> d;
        v.push_back({p, d});
    }

    sort(v.begin(), v.end(), cmp);

    for(pii ele: v) {
        int p = ele.first;
        int d = ele.second;

        int min_p = p;
        int min_p_idx = -1;
        for(int i=1; i<=d; i++) {
            if(min_p > lectures[i]) {
                min_p = lectures[i];
                min_p_idx = i;
            }
        }

        if(min_p_idx == -1) continue;
        lectures[min_p_idx] = p;
    }

    int ans = 0;
    for(int i=1; i<=N; i++) ans += lectures[i];
    cout << ans;

    return 0;
}