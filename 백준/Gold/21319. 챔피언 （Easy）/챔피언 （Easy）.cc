#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, K;
int max_score;

struct Node {
    int num;
    int score;
};

vector<Node> vec;
vector<int> input;

bool champion(int n) {
    if (n == 0) {
        return false;
    }
    int score = vec[n].score;
    int i;
    for (i = 0; i <= n; i++) {
        score += vec[i].num;
    }
    score--;
    // cout << "score1: " << score << '\n';

    while (i < vec.size() && score > vec[i].score) {
        // cout << vec[i].score << '\n';
        score += vec[i].num;
        i++;
    }

    // cout << "score: " << score << '\n';
    if (score > max_score) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        input.push_back(x);
        max_score = max(max_score, x);
    }

    int cnt = 1;
    int pre = input[0];
    for (int i = 1; i < N; i++) {
        int cur = input[i];
        if (cur != pre) {
            vec.push_back({cnt, pre});
            pre = input[i];
            cnt = 1;
        } else {
            cnt++;
        }
    }
    vec.push_back({cnt, pre});

    // for(auto ele: vec) {
    //     cout << ele.num << ' ' << ele.score << '\n';
    // }

    if (vec.size() == 1) {
        if (vec[0].num == 1) {
            cout << 1;
            return 0;
        } else {
            cout << -1;
            return 0;
        }
    } else if (vec.size() == 2) {
        cout << 1 + vec[0].num;
        return 0;
    }

    int high = vec.size() - 1;
    int low = 0;
    int mid = (high + low) / 2;

    int pre_mid = mid;
    bool flag = false;
    while (high > low) {
        // pre_mid = mid;
        mid = (high + low) / 2;
        // cout << mid << '\n';
        if (champion(mid)) {
            // flag = true;
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    if (champion((low + high) / 2)) {
        mid = (low + high) / 2;
    }

    // if (!flag) {
    //     int idx = 1;
    //     for (int i = 0; i < vec.size(); i++) {
    //         if (vec[i].score == max_score) {
    //             break;
    //         }
    //         idx += vec[i].num;
    //     }
    //     cout << idx;
    //     return 0;
    // }
    // cout << mid;

    int base = 1;
    for (int i = 0; i < mid; i++) {
        // cout << i << ' ' << vec[i].num << '\n';
        base += vec[i].num;
    }

    int ans = base;
    for (int i = mid; i < vec.size(); i++) {
        cout << ans << ' ';
        ans += vec[i].num;
    }

    return 0;
}