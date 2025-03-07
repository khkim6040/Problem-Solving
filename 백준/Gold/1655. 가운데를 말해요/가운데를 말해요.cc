#include <iostream>
#include <queue>

#define INIT_VALUE 222222222

using namespace std;

priority_queue<int> below;
priority_queue<int, vector<int>, greater<int>> above;
int mid = INIT_VALUE;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    while (N--) {
        int x;
        cin >> x;
        int below_size = below.size();
        int above_size = above.size();
        // 1st step
        if (mid == INIT_VALUE) {
            mid = x;
            cout << mid << '\n';
            continue;
        }

        if (mid == x) {
            // There are only two cases possible
            // 1. above_size == below_size + 1
            // 2. above_size == below_size
            // There is no case where above_size + 1 == below_size
            // Because if so, below.top() should be the mid
            if (above_size > below_size) {
                below.push(x);
            } else if (above_size == below_size) {
                above.push(x);
            }
        } else if (mid > x) {
            below.push(x);
            if (below.size() > above.size()) {
                above.push(mid);
                mid = below.top();
                below.pop();
            }
        } else {
            above.push(x);
            if (above.size() > below.size() + 1) {
                below.push(mid);
                mid = above.top();
                above.pop();
            }
        }

        cout << mid << '\n';
    }

    return 0;
}