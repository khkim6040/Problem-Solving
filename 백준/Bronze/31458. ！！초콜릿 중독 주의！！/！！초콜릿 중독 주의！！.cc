#include <iostream>
#include <string>
using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        bool is_even = true;
        string input;
        int n;
        cin >> input;
        int i = 0;
        for (i; i < input.size(); i++) {
            if (input[i] != '!') {
                n = input[i] - '0';
                break;
            }
        }
        int front_size = i;
        int rear_size = input.size() - (i + 1);
        if (rear_size >= 1) {
            n = 1;
        }
        n = front_size % 2 == 1 ? !n : n;
        cout << n << '\n';
    }

    return 0;
}