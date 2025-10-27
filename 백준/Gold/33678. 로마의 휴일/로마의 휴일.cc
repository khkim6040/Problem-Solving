#include <iostream>

#define ll long long

using namespace std;

ll N, K, X;

ll prefSum[200005];

bool check(int vacationDays) {
    
    for(int i=1; i<=N-vacationDays+1; i++) {
        if(prefSum[i-1]*X + prefSum[N] - prefSum[i+vacationDays-1] >= K) return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K >> X;

    for(int i=1; i<=N; i++) {
        ll x;
        cin >> x;
        prefSum[i] = prefSum[i-1] + x;
    }

    int l = 1;
    int r = N;
    while(l<=r) {
        int m = (l+r)/2;

        if(check(m)) {
            // cout << "PASS: " << m << '\n';
            l = m + 1;
        } else {
            // cout << "NO: " << m << '\n';
            r = m - 1;
        }
    }

    if(r==0) {
        cout << -1;
    } else {
        cout << r;
    }


    return 0;
}