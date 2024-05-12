#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define SIZE 55

int N, M;
int b[SIZE][SIZE];
vector<vector<int>> dist_info;  // 도시-치킨집 거리 정보
vector<pair<int, int>> chi_location;
vector<pair<int, int>> house_location;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> b[i][j];
            if (b[i][j] == 1) {
                house_location.push_back({i, j});
            } else if (b[i][j] == 2) {
                chi_location.push_back({i, j});
            }
        }
    }

    int house_size = house_location.size();
    int chi_size = chi_location.size();
    dist_info.assign(house_size, vector<int>());
    for (int i = 0; i < house_size; i++) {
        auto [r, c] = house_location[i];
        for (int j = 0; j < chi_size; j++) {
            auto [r_, c_] = chi_location[j];
            dist_info[i].push_back({abs(r - r_) + abs(c - c_)});
        }
    }

    vector<bool> chk(chi_size);
    for (int i = 0; i < M; i++) {
        chk[i] = true;
    }
    int min_dist = 2111111111;
    do {
        // for (int i = 0; i < chi_size; i++) {
        //     cout << chk[i];
        // }
        // cout << '\n';
        int dist = 0;
        for (auto dist_ : dist_info) {
            int local_min = 2111111111;
            for (int i = 0; i < chi_size; i++) {
                if (chk[i]) {
                    local_min = min(local_min, dist_[i]);
                }
            }
            dist += local_min;
        }

        min_dist = min(min_dist, dist);

    } while (prev_permutation(chk.begin(), chk.end()));

    cout << min_dist;

    return 0;
}