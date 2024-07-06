#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll N;
string S;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> S;
    N = S[0] - '0';
    int size = S.size();
    if (size == 1) {
        cout << S;
        return 0;
    }

    string ans = "";
    if (S[1] - '0' < 5) {
        ans += S[0];
        ans.append((size - 1), '0');
        cout << ans;
    } else {
        char t = (S[0] + 1);
        if (t == ':') {
            ans += "10";
        } else {
            ans += t;
        }
        ans.append((size - 1), '0');
        cout << ans;
    }

    return 0;
}