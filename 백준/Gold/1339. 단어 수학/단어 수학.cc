#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int N;
int weights[26];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        int size = str.size();
        int weight = pow(10, size - 1);
        // cout << weight << '\n';
        for (int i = 0; i < size; i++) {
            int idx = str[i] - 'A';
            weights[idx] += weight;
            weight /= 10;
        }
    }

    int point = 9;
    long long ans = 0;
    for (int i = 0; i < 26; i++) {
        int max_idx = 0;
        int max_val = 0;
        for (int j = 0; j < 26; j++) {
            if (max_val < weights[j]) {
                max_val = weights[j];
                max_idx = j;
            }
        }

        if (max_val == 0) {
            break;
        }

        ans += point * max_val;
        weights[max_idx] = 0;
        point--;
    }

    cout << ans;

    return 0;
}