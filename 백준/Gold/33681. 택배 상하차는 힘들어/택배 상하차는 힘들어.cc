#include <iostream>
#include <vector>

#define ll long long


using namespace std;

int N, K, X;
ll A[100005];
ll packages[100005];
ll updown[100005];
vector<vector<int>> g(100005);



void dfs(int cur, int prev) {
    
    for(int next: g[cur]) {
        if(next == prev) continue;
        dfs(next, cur);
        packages[cur] += packages[next];
    }

    ll max_cnt = -1;
    int max_cnt_idx = -1;
    for(int next: g[cur]) {
        // cout << next << ' ';

        if(next == prev) continue;
        if(max_cnt < packages[next]) {
            max_cnt = max(max_cnt, packages[next]);
            max_cnt_idx = next;
        }
    }
    // cout << '\n';
    for(int next: g[cur]) {
        if(next == prev) continue;
        if(next == max_cnt_idx) continue;
        updown[cur] += packages[next]*2;
    }



}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> A[i];
        packages[i] = A[i];
    }

    for(int i=0; i<N-1; i++) {
        int s, e;
        cin >> s >> e;
        g[s].push_back(e);
        g[e].push_back(s);
    }

    dfs(1, -1);

    ll ans = (packages[1] - A[1])*2;
    // cout << ans << '\n';
    for(int i=2; i<=N; i++) {
        // cout << updown[i] << '\n';
        ans += updown[i];
    }


    cout << ans;

    return 0;

}
