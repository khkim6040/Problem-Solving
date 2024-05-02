#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
typedef long long ll;
using namespace std;

int N, K;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    string S;
    cin >> S;

    int r = S.size() - 1;
    int l = 0;
    while (r > l && K > 0) {
        while (r >= 0 && S[r] == 'C') {
            r--;
        }
        while (l < S.size() && S[l] == 'P') {
            l++;
        }
        if (r > l) {
            S[r] = 'C';
            S[l] = 'P';
            K--;
            r--;
            l++;
        }
    }

    long long P_cnt = 0;
    long long ans = 0;
    for (auto ele : S) {
        if (ele == 'C') {
            ans += P_cnt * (P_cnt - 1) / 2;
        } else {
            P_cnt++;
        }
    }

    cout << ans;
}