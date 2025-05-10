#include <iostream>

using namespace std;

int N, D, K;
int S[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> D >> K;
    int ans = 0;
    int max_ = 0;
    for(int i=0; i<N; i++) {
        int S;
        cin >> S;
        max_ = max(max_, S);
        // 4/2 => 2 => K%S == 0 일 때는 K/S - (K%S==1) 해줘야 함
        // K/S => 5/3 => 1 
    }

    int days = K/max_;
    // cout << days << '\n';
    ans += (D-1)/days;

    cout << ans;


    return 0;
}