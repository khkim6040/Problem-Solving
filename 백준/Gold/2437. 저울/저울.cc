#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    if(v[0] > 1) {
        cout << 1;
        return 0;
    }

    int sum = 0;
    int ans = -1;
    for(int e: v) {
        if(sum+1 < e) {
            ans = sum+1;
            break;
        }
        sum += e;
    }

    if(ans == -1) ans = sum+1;

    cout << ans;
    
    return 0;
}