#include <iostream>
#include <vector>
using namespace std;

int K;

struct Gear {
    int pivot = 0;  // 12시 방향 인덱스
    int values[8] = {
        0,
    };
    int get_left() {
        return this->values[(8 + (this->pivot - 2)) % 8];
    }
    int get_right() {
        return this->values[(this->pivot + 2) % 8];
    }
};

vector<Gear> vec(4);

void turn(int x, bool is_ccw, bool do_left, bool do_right) {
    if (do_left && x >= 1 && vec[x - 1].get_right() != vec[x].get_left()) {
        turn(x - 1, !is_ccw, true, false);
    }
    if (do_right && x <= 2 && vec[x + 1].get_left() != vec[x].get_right()) {
        turn(x + 1, !is_ccw, false, true);
    }

    vec[x].pivot = (8 + vec[x].pivot + (is_ccw ? 1 : -1)) % 8;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            char x;
            cin >> x;
            vec[i].values[j] = x - '0';
        }
    }

    // for (auto ele : vec) {
    //     for (int i = 0; i < 8; i++) {
    //         cout << ele.values[i] << ' ';
    //     }
    //     cout << '\n';
    // }

    cin >> K;
    while (K--) {
        int starter, is_ccw;
        cin >> starter >> is_ccw;
        is_ccw = is_ccw == -1 ? 1 : 0;
        turn(starter - 1, is_ccw, true, true);
    }

    int ans = 0;
    int mul = 1;
    for (auto gear : vec) {
        if (gear.values[gear.pivot] == 1) {
            ans += mul;
        }
        mul *= 2;
    }

    cout << ans;

    return 0;
}