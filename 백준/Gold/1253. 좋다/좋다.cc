#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N;
vector<int> v;
unordered_map<int, int> m;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i=1; i<=N; i++) {
        int x;
        cin >> x;
        m[x]++;
        v.push_back(x);
    }

    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(j==i) continue;
            int target = v[i] - v[j];
            if(!m[target]) continue;
            if(target == v[i] && m[target] < 2) continue;
            if(target == v[j] && m[target] < 2) continue;
            if(target == v[i] && target == v[j] && m[target] < 3) continue;
            ans++;
            break;
        }
    }

    cout << ans;

    return 0;
}