#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

#define ll long long
#define pii pair<int, int>
#define INF 211111111

using namespace std;

int b[9][9];
vector<pii> v;
int N;
bool possible[88][10];

void check_row(int idx, int r, int c) {
    for(int j=0; j<9; j++) {
        int x = b[r][j];
        possible[idx][x] = false;
    }
}

void check_col(int idx, int r, int c) {
    for(int i=0; i<9; i++) {
        int x = b[i][c];
        possible[idx][x] = false;
    }
}

void check_box(int idx, int r, int c) {
    int base_r = r/3;
    int base_c = c/3;
    for(int i=0; i<3; i++) {
        int rr = base_r*3 + i;
        for(int j=0; j<3; j++) {
            int cc = base_c*3 + j;
            int x = b[rr][cc];
            possible[idx][x] = false;
        }
    }
}

bool backtrack(int idx) {

    if(idx == N) {
        return true;
    }

    pii cur = v[idx];
    int r = cur.first;
    int c = cur.second;

    fill_n(&possible[idx][0], 10, true);

    check_row(idx, r, c);
    check_col(idx, r, c);
    check_box(idx, r, c);

    bool flag = false; 

    for(int i=1; i<=9; i++) {
        if(!possible[idx][i]) continue;
        b[r][c] = i;
        flag = backtrack(idx+1);
        if(flag) return true;
        b[r][c] = 0;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> b[i][j];
            if(b[i][j] == 0) {
                v.push_back({i, j});
            }
        }
    }


    N = v.size();
    backtrack(0);

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout << b[i][j] << ' ';
        }
        cout << '\n';
    }


     
    return 0;
}