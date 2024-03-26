#include <iostream>
#include <set>
#include <string>
#include <tuple>
using namespace std;

int H, W, R, C, D;
bool is_dust[65][65];
int A[65][65];
int B[65][65];
// set<tuple<int, int, int>> visited_route;
bool visited_route[65][65][4];
bool is_visited_route_empty = true;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void move_bot(int &r, int &c, int &d, bool has_cleaned) {
    d = has_cleaned ? (d + A[r][c]) % 4 : (d + B[r][c]) % 4;
    r = r + dy[d];
    c = c + dx[d];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> H >> W >> R >> C >> D;
    int dust_cnt = H * W;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            is_dust[i][j] = true;
        }
    }
    for (int i = 0; i < H; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < W; j++) {
            A[i][j] = int(str[j]) - '0';
        }
    }

    for (int i = 0; i < H; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < W; j++) {
            B[i][j] = int(str[j]) - '0';
        }
    }

    long long clock = 0;
    long long end_time = 1;
    int r = R;
    int c = C;
    int d = D;
    while (true) {
        if (r < 0 || c < 0 || r >= H || c >= W || dust_cnt == 0) {
            if (is_visited_route_empty)
                end_time = clock;
            break;
        }

        if (is_dust[r][c]) {
            is_dust[r][c] = false;
            dust_cnt--;
            if (!is_visited_route_empty)
                fill_n(&visited_route[0][0][0], 65 * 65 * 4, false);
            is_visited_route_empty = true;
            d = (d + A[r][c]) % 4;
            r = r + dy[d];
            c = c + dx[d];
        } else {
            // turn first to check cycle
            d = (d + B[r][c]) % 4;
            if (visited_route[r][c][d]) {
                break;
            }
            if (is_visited_route_empty)
                end_time = clock;
            // insert current position, then move
            visited_route[r][c][d] = true;
            is_visited_route_empty = false;
            r = r + dy[d];
            c = c + dx[d];
        }
        // cout << clock << ' ' << has_cleaned << ' ' << r << c << d << '\n';
        clock++;
    }

    cout << end_time;
    return 0;
}