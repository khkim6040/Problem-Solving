#include <iostream>
using namespace std;

int N, B, C;
int rooms[1000005];
long long ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> rooms[i];
    }
    cin >> B >> C;

    for (int i = 0; i < N; i++) {
        int temp = max(rooms[i] - B, 0);
        int num = temp / C;
        num = temp % C != 0 ? num + 1 : num;
        ans += num + 1;
    }

    cout << ans;
    return 0;
}