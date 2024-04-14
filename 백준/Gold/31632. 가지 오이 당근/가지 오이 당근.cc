#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

#define WIN 0
#define DRAW 1
#define LOSE 2

char to_char[3] = {'G', 'O', 'D'};
char to_char_res[3] = {'W', 'D', 'L'};

struct Gazi {
    int idx;
    int res;
};

ll T, N;
vector<Gazi> inputs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N;
        inputs.assign(N, Gazi());
        vector<int> idxs;
        for (int i = 0; i < N; i++) {
            char x;
            cin >> x;
            if (x == 'G') {
                idxs.push_back(0);
            } else if (x == 'O') {
                idxs.push_back(1);
            } else if (x == 'D') {
                idxs.push_back(2);
            } else {
                idxs.push_back(3);
            }
        }

        vector<int> ress;
        bool is_W = false;
        bool is_L = false;
        bool is_D = false;
        for (int i = 0; i < N; i++) {
            char x;
            cin >> x;
            if (x == 'W') {
                is_W = true;
                ress.push_back(0);
            } else if (x == 'D') {
                is_D = true;
                ress.push_back(1);
            } else if (x == 'L') {
                is_L = true;
                ress.push_back(2);
            }
        }

        if ((is_W && !is_L && !is_D) || (!is_W && is_L && !is_D) || (is_D && (is_W || is_L))) {
            cout << "NO" << '\n';
            continue;
        }

        for (int i = 0; i < N; i++) {
            inputs[i] = {idxs[i], ress[i]};
            // cout << to_char[inputs[i].idx] << ' ' << to_char_res[inputs[i].res] << '\n';
        }

        bool W[4] = {
            false,
        };
        bool D[4] = {
            false,
        };
        bool L[4] = {
            false,
        };
        for (auto ele : inputs) {
            if (ele.idx == 3) continue;
            if (ele.res == WIN) {
                W[ele.idx] = 1;
            } else if (ele.res == DRAW) {
                D[ele.idx] = 1;
            } else if (ele.res == LOSE) {
                L[ele.idx] = 1;
            } else {
                cout << "DFSDFSDFSDFS";
                continue;
            }
        }
        vector<int> W_idx;
        vector<int> D_idx;
        vector<int> L_idx;
        bool flag = false;
        for (int i = 0; i < 3; i++) {
            int cnt = 0;
            if (W[i]) {
                // cout << "W: " << to_char[i] << '\n';
                cnt++;
                W_idx.push_back(i);
            }
            if (D[i]) {
                // cout << "D: " << to_char[i] << '\n';
                cnt++;
                D_idx.push_back(i);
            }
            if (L[i]) {
                // cout << "L: " << to_char[i] << '\n';
                cnt++;
                L_idx.push_back(i);
            }
            if (cnt >= 2) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "NO" << '\n';
            continue;
        }

        int W_size = W_idx.size();
        int D_size = D_idx.size();
        int L_size = L_idx.size();
        if (W_size >= 2 || L_size >= 2 || (D_size >= 1 && (W_size >= 1 || L_size >= 1))) {
            cout << "NO" << '\n';
            continue;
        }
        int w_idx = W_size == 1 ? W_idx[0] : -1;
        int l_idx = L_size == 1 ? L_idx[0] : -1;

        if (w_idx != -1 && l_idx != -1 && l_idx != (w_idx + 1) % 3) {
            cout << "NO" << '\n';
            continue;
        }

        char res_to_idx_char[3] = {};

        if (D_size == 1) {
            res_to_idx_char[DRAW] = to_char[D_idx[0]];
        } else if (D_size == 2) {
            int temp = 3 - D_idx[0] - D_idx[1];
            res_to_idx_char[DRAW] = to_char[temp];
        } else {
            if (w_idx != -1) {
                res_to_idx_char[WIN] = to_char[w_idx];
                res_to_idx_char[LOSE] = to_char[(w_idx + 1) % 3];

            } else if (l_idx != -1) {
                res_to_idx_char[WIN] = to_char[(l_idx + 2) % 3];
                res_to_idx_char[LOSE] = to_char[l_idx];
            } else {
                // 모두 ?인 상황
                // WLD가 다 있으면 안됨
                int is_W = false;
                int is_L = false;
                int is_D = false;
                for (auto ele : inputs) {
                    if (ele.res == WIN) {
                        is_W = true;
                    } else if (ele.res == LOSE) {
                        is_L = true;
                    } else {
                        is_D = true;
                    }
                }
                if ((is_W || is_L) && is_D) {
                    cout << "NO" << '\n';
                    continue;
                }
                res_to_idx_char[WIN] = to_char[0];
                res_to_idx_char[LOSE] = to_char[1];
                res_to_idx_char[DRAW] = to_char[2];
            }
        }

        cout << "YES" << '\n';
        for (auto ele : inputs) {
            if (ele.idx != 3) {
                cout << to_char[ele.idx];
            } else {
                cout << res_to_idx_char[ele.res];
            }
        }
        cout << '\n';
    }

    return 0;
}