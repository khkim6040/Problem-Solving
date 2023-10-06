#include <iostream>
using namespace std;

int N, Q;
int possible_amount[100005];  // 주량
int left_amount[100005];      // 더 마실 수 있는 양
int parent[100005];

int getParent(int i) {
    if (parent[i] == i) {
        return i;
    } else {
        return parent[i] = getParent(parent[i]);
    }
}

void onion(int x, int y) {
    parent[x] = getParent(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        possible_amount[i] = left_amount[i] = x;
        parent[i] = i;
    }
    parent[N + 1] = N + 1;

    int command;
    int i, x;
    while (Q--) {
        cin >> command;
        if (command == 1) {
            cin >> i >> x;
            for (i; i <= N && x >= 0; i = parent[i]) {
                int temp = left_amount[i];
                left_amount[i] = max(left_amount[i] - x, 0);
                x -= temp;
                if (left_amount[i] == 0) {
                    onion(i, i + 1);
                }
            }
        } else {
            cin >> i;
            cout << possible_amount[i] - left_amount[i] << '\n';
        }
    }

    return 0;
}