#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<int> vec(N);
    for(int i=0; i<N; i++) {
        cin >> vec[i];
    }

    vector<int> ans;
    ans.assign(N, 2111111111);
    int ret = 0;
    for(int cur: vec) {
        int idx = lower_bound(ans.begin(), ans.end(), cur) - ans.begin();
        ans[idx] = cur;
        ret = max(ret, idx+1);
    }

    cout << ret;
    
    return 0;
}