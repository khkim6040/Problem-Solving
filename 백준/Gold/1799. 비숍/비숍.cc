#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int b[15][15];
bool visited[15][15];
int N, ans;

vector<pair<int, int>> black;
vector<pair<int, int>> white;
int b_s, w_s, max_c;

bool check(int r, int c) {
    int i = r;
    int j = c;
    while (b[i++][j++] != -1) {
        if (visited[i][j]) return false;
    }
    i = r;
    j = c;
    while (b[i++][j--] != -1) {
        if (visited[i][j]) return false;
    }
    i = r;
    j = c;
    while (b[i--][j++] != -1) {
        if (visited[i][j]) return false;
    }
    i = r;
    j = c;
    while (b[i--][j--] != -1) {
        if (visited[i][j]) return false;
    }
    return true;
}

void dfs(const int n, const int cnt, const bool is_b) {
    int s = is_b ? b_s : w_s;
    if (cnt == 11) {
        cout << n << '\n';
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cout << visited[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    max_c = max(max_c, cnt);
    for (int i = n; i < s; i++) {
        auto p = is_b ? black[i] : white[i];
        int r = p.first;
        int c = p.second;
        if (!check(r, c)) continue;

        visited[r][c] = true;
        dfs(i + 1, cnt + 1, is_b);
        visited[r][c] = false;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    fill_n(&b[0][0], 15 * 15, -1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> b[i][j];
            if (b[i][j] == 1 && (i + j) % 2 == 0) {
                black.push_back({i, j});
            } else if ((b[i][j] == 1 && (i + j) % 2 == 1)) {
                white.push_back({i, j});
            }
        }
    }
    b_s = black.size();
    w_s = white.size();

    dfs(0, 0, 1);
    ans += max_c;
    // cout << max_c << '\n';
    max_c = 0;

    fill_n(&visited[0][0], 15 * 15, false);
    dfs(0, 0, 0);
    ans += max_c;
    // cout << max_c << '\n';
    cout << ans;
    return 0;
}