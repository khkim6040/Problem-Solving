#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
typedef long long ll;
using namespace std;

int N, M;
struct Point {
    int r;
    int c;
    int s;
    bool operator<(const Point &other) const {
        return s > other.s;
    }
};

int S[1005][1005];
priority_queue<Point> pq;

int H[1005][1005];
bool visited[1005][1005];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int get_local_height(int r, int c) {
    int height = -1;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr > 0 && nr <= N && nc > 0 && nc <= M && H[nr][nc] != -1) {
            height = max(height, H[nr][nc]);
        }
    }
    return height;
}

void find_and_fill(int r, int c, int size) {
    int height = -1;

    queue<pair<int, int>> q;
    queue<pair<int, int>> fill_q;
    q.push({r, c});
    fill_q.push({r, c});
    visited[r][c] = true;
    // find H
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        height = max(height, get_local_height(r, c) + 1);
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr > 0 && nr <= N && nc > 0 && nc <= M && S[nr][nc] == size && !visited[nr][nc]) {
                q.push({nr, nc});
                fill_q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
    // fill H
    while (!fill_q.empty()) {
        int r = fill_q.front().first;
        int c = fill_q.front().second;
        fill_q.pop();
        H[r][c] = height;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> S[i][j];
            pq.push({i, j, S[i][j]});
        }
    }

    fill_n(&H[0][0], 1005 * 1005, -1);
    vector<Point> vec;

    while (!pq.empty()) {
        Point cur = pq.top();
        // cout << r << c << s << '\n';
        pq.pop();
        vec.push_back(cur);
    }

    for (auto ele : vec) {
        if (!visited[ele.r][ele.c]) {
            find_and_fill(ele.r, ele.c, ele.s);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << H[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}