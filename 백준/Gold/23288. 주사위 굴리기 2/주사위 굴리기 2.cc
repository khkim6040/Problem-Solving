#include <iostream>
#include <vector>
#include <cstring>

#define E 0
#define S 1
#define W 2
#define N 3
using namespace std;

typedef pair<int, int> pii;

int N_, M, K;
int dir = E;

int dice[3] = {6, 5, 3}; // 아랫면 기준 초기값 {아랫면, 아랫면에서 남쪽(정면), 아랫면에서 동쪽(오른쪽)} 
int b[22][22];
bool visited[22][22];

// E, S, W, N 과 맞춤. is_possible()에서 사용
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

pii roll(pii cur) {
    pii ret = cur;
    // dice 변경
    int tmp[3];
    memcpy(&tmp[0], &dice[0], sizeof(dice));
    if(dir == E) {
        tmp[0] = dice[2];
        tmp[2] = 7-dice[0];
        ret.second++;
    } else if(dir == S) {
        tmp[0] = dice[1];
        tmp[1] = 7-dice[0];
        ret.first++;
    } else if(dir == W) {
        tmp[0] = 7-dice[2];
        tmp[2] = dice[0];
        ret.second--;
    } else {
        tmp[0] = 7-dice[1];
        tmp[1] = dice[0];
        ret.first--;
    }
    memcpy(&dice[0], &tmp[0], sizeof(dice));

    return ret;
}

int dfs(int pr, int pc, const int target) {
    int ret = 1;
    visited[pr][pc] = true;

    for(int i=0; i<4; i++) {
        int r = pr + dr[i];
        int c = pc + dc[i];
        if(r<=0 || r>N_ || c<=0 || c>M || b[r][c] != target || visited[r][c]) continue;
        ret += dfs(r, c, target);
    }

    return ret;
}

void set_next_dir(int board_value) {
    // dice[0], b[cur.first][cur.second]
    int bottom = dice[0];
    if(bottom > board_value) {
        dir = (dir+1)%4;
    } else if(bottom < board_value) {
        dir = (dir+4-1)%4;
    }
}

bool roll_possible(pii cur) {
    int r = cur.first + dr[dir];
    int c = cur.second + dc[dir];

    return !(r<=0 || r>N_ || c<=0 || c>M);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N_ >> M >> K;

    for(int i=1; i<=N_; i++) {
        for(int j=1; j<=M; j++) {
            cin >> b[i][j];
        }
    }

    pii cur = {1, 1};
    int ans = 0;
    int cnt = 1;
    while(K--) {
        // cout << cur.first << ' ' << cur.second << ' ' << dir << '\n';
        if(!roll_possible(cur)) {
            dir = (dir+2)%4;
            // cout << "CHANGE " <<  cur.first << ' ' << cur.second << ' ' << dir << '\n';
        } 
        cur = roll(cur);
        // cout << cur.first << ' ' << cur.second << '\n';
        fill_n(&visited[0][0], 22*22, false);
        ans += (b[cur.first][cur.second] * dfs(cur.first, cur.second, b[cur.first][cur.second]));
        // cout << ans << '\n';
        set_next_dir(b[cur.first][cur.second]);
    }

    cout << ans;
    
    return 0;
}