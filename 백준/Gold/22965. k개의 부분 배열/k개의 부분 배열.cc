#include <iostream>
using namespace std;

int N;
int start, pre, cur;
int answer = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> pre;
    start = pre;
    for (int i = 1; i < N; i++) {
        cin >> cur;
        if (cur > pre) {
            if (answer == 2 && cur > start) {
                answer = 3;
                break;
            }
        } else {
            if (answer == 1 && cur < start) {
                answer = 2;
            } else {
                answer = 3;
                break;
            }
        }
        pre = cur;
    }

    cout << answer;
    return 0;
}