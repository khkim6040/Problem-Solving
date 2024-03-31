#include <iostream>
using namespace std;

int N;
int S[200005];
int in_cnt[10];
int ans;

int check(int back, int front) {
    int tot = 0;
    for (int i = 1; i < 10; i++) {
        tot += in_cnt[i] == 0 ? 0 : 1;
    }
    return tot;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    if (N == 1) {
        cout << 1;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int front = 1;
    int back = 0;
    ans = 1;
    in_cnt[S[back]]++;
    while (front < N) {
        int x = S[front];
        in_cnt[x]++;
        if (in_cnt[x] == 1) {
            while (check(back, front) > 2) {
                in_cnt[S[back]]--;
                back++;
            }
        }
        ans = max(ans, front - back + 1);
        // cout << "front: " << front << ' ' << "back: " << back << ' ' << "ans: " << ans << '\n';
        front++;
    }

    cout << ans;

    return 0;
}
