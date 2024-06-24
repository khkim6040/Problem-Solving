#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> A, B, C, D, AB, CD;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }

    for (int a : A) {
        for (int b : B) {
            AB.push_back(a + b);
        }
    }

    for (int c : C) {
        for (int d : D) {
            CD.push_back(c + d);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    long long ans = 0;
    for (auto ele : AB) {
        int cnt = (upper_bound(CD.begin(), CD.end(), -ele) - CD.begin()) - (lower_bound(CD.begin(), CD.end(), -ele) - CD.begin());
        ans += cnt;
    }

    cout << ans;

    return 0;
}