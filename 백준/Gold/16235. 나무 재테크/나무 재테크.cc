#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define pii pair<int, int>

int N, M, K, time;
int A[11][11];
int nut[11][11];
int dead[11][11];
vector<vector<vector<int>>> b(11, vector<vector<int>>(11, vector<int>(0)));
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            nut[i][j] = 5;
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        b[x][y].push_back(z);
    }

    while (time != K) {
        time++;
        // spring
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                vector<int> v = b[i][j];
                sort(v.begin(), v.end());
                vector<int> v_n;
                for (int t : v) {
                    // cout << i << ' ' << j << ' ' << t << '\n';
                    if (nut[i][j] < t) {
                        dead[i][j] += t / 2;
                        continue;
                    }
                    // cout << i << ' ' << j << ' ' << t << '\n';

                    nut[i][j] -= t;
                    v_n.push_back(t + 1);
                }
                b[i][j] = v_n;
            }
        }
        // summer
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                nut[i][j] += dead[i][j];
                dead[i][j] = 0;
            }
        }
        // fall
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int t : b[i][j]) {
                    if (t % 5 != 0) continue;
                    for (int k = 0; k < 8; k++) {
                        int r = i + dr[k];
                        int c = j + dc[k];
                        if (r >= 1 && c >= 1 && r <= N && c <= N) {
                            b[r][c].push_back(1);
                        }
                    }
                }
            }
        }
        // winter
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                nut[i][j] += A[i][j];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += b[i][j].size();
        }
    }

    cout << ans;
    return 0;
}
