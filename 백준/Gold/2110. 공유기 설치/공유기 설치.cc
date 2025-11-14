#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

#define ll long long
#define pii pair<int, int>
#define INF 211111111

using namespace std;

int N, C;
vector<int> v;

bool check(int target) {
    int prev = v[0];
    int cnt = 1;
    for(int i=1; i<N; i++) {
        int cur = v[i];
        if(cur-prev >= target) {
            prev = cur;
            cnt++;
        }
    }

    return cnt >= C;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> C;
    v.resize(N);
    for(int i=0; i<N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int min_gap = 2111111111;
    for(int i=0; i<N-1; i++) {
        min_gap = min(min_gap, v[i+1]-v[i]);
    }

    int l = min_gap;
    int r = v[N-1] - v[0];

    while(l<=r) {
        int m = (l+r)/2;

        if(check(m)) {
            l = m+1;
        } else {
            r = m-1;
        }
    }

    cout << r;

     
    return 0;
}