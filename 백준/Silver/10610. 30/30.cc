#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef long long ll;

string N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int sum = 0;
    bool is_zero = false;
    priority_queue<int> pq;
    for (char s : N) {
        int n = s - '0';
        pq.push(n);
        sum += n;
        if (n == 0) {
            is_zero = true;
        }
    }

    if ((sum % 3 == 0 && is_zero)) {
        while (!pq.empty()) {
            cout << pq.top();
            pq.pop();
        }
    } else {
        cout << -1;
    }

    return 0;
}