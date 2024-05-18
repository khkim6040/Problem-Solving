#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define Point pair<int, int>

int N;

// 문제의 좌표축 고려
int _cos[] = {1, 0, -1, 0};
int _sin[] = {0, -1, 0, 1};

inline Point get_rotated_point(int px, int py, int x, int y, int d) {
    return {(x - px) * _cos[d] - (y - py) * _sin[d] + px, (x - px) * _sin[d] + (y - py) * _cos[d] + py};
}

vector<vector<Point>> point_template(11);  // d=0인 경우
int b[105][105];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    point_template[0].push_back({0, 0});
    point_template[0].push_back({1, 0});
    for (int i = 1; i <= 10; i++) {
        int pre_size = point_template[i - 1].size();
        auto [px, py] = point_template[i - 1][pre_size - 1];
        int cur_size = pow(2, i) + 1;
        for (int j = 0; j < cur_size; j++) {
            if (j < pre_size) {
                point_template[i].push_back(point_template[i - 1][j]);
                // cout << "<" << '\n';
            } else {
                point_template[i].push_back(get_rotated_point(px, py, point_template[i - 1][cur_size - j - 1].first, point_template[i - 1][cur_size - j - 1].second, 3));
                // cout << ">" << '\n';
            }
            // cout << point_template[i][j].first << ' ' << point_template[i][j].second << '\n';
        }
    }

    // for (int i = 10; i <= 10; i++) {
    //     for (auto p : point_template[i]) {
    //         cout << p.first << ' ' << p.second << '\n';
    //     }
    // }

    cin >> N;
    while (N--) {
        int px, py, d, g;
        cin >> px >> py >> d >> g;
        // cout << d << '\n';
        for (auto p : point_template[g]) {
            auto [x, y] = p;
            auto [nx, ny] = get_rotated_point(px, py, x + px, y + py, d);
            // cout << x << ' ' << y << ' ' << nx << ' ' << ny << ' ' << '\n';
            if (nx >= 0 || nx <= 100 || ny >= 0 || ny <= 100) {
                b[nx][ny] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            // if (b[i][j] == 1) {
            //     cout << i << ' ' << j << '\n';
            // }
            if (b[i][j] && b[i + 1][j] && b[i][j + 1] && b[i + 1][j + 1]) {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}