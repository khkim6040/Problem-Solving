#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<bool> temp;
vector<vector<int>> b;

int get_sum(int n) {
    bool flag = temp[n];
    int res = 0;
    for (int i = 0; i < N; i++) {
        if (flag == temp[i]) {
            res += b[n][i];
        }
    }
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    temp.assign(N, false);
    b.assign(N, vector<int>());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            b[i].push_back(x);
        }
    }

    for (int i = 0; i < N / 2; i++)
        temp[i] = true;

    int min_diff = 2111111111;
    do {
        // for (int i = 0; i < N; i++) {
        //     cout << temp[i] << ' ';
        // }
        // cout << '\n';
        int team1 = 0;
        int team2 = 0;
        for (int i = 0; i < N; i++) {
            if (temp[i]) {
                team1 += get_sum(i);
            } else {
                team2 += get_sum(i);
            }
        }
        min_diff = min(min_diff, abs(team1 - team2));
    } while (prev_permutation(temp.begin(), temp.end()));

    cout << min_diff;

    return 0;
}