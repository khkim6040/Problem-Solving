#include <iostream>
#include <vector>

#define U 0
#define D 1
#define L 2
#define R 3
#define pii pair<int, int>
#define RATE_SIZE 9
using namespace std;

int N;
int ans;
int b[505][505];

int dr[] = {-1, 1, 0, 0};
int dc[] = { 0, 0, -1, 1};
int rate[RATE_SIZE] = {2, 10, 7, 1, 5, 10, 7, 1, 2}; // a는 따로 계산
// L 기준 작성
pii rate_pos[RATE_SIZE] = {{-2, 0}, {-1, -1}, {-1, 0}, {-1, 1}, {0, -2}, {1, -1}, {1, 0}, {1, 1}, {2, 0}};

struct Position {
    int r, c, dir;

    void print_() {
        cout << r << ' ' << c << ' ' << dir << '\n';
    }
};

pii get_rate_delta(pii pos, int dir) {
    if(dir == U) {
        // L 진행 기준 시계방향 90
        return {pos.second, -pos.first};
    } else if(dir == D) {
        // 반시계 90
        return {-pos.second, pos.first};
    } else if(dir == L) {
        return pos;
    } else if(dir == R) {
        // 좌우대칭
        return {pos.first, -pos.second};
    }
}

int tornado(Position pos) {
    int ret = 0;
    int dir = pos.dir;
    int r = pos.r + dr[dir];
    int c = pos.c + dc[dir];

    int amount = b[r][c];
    int alpha_amount = amount;
    b[r][c] = 0;
    
    for(int i=0; i<RATE_SIZE; i++) {
        int rate_amount = amount*rate[i]/100;
        alpha_amount -= rate_amount;

        pii rate_delta = get_rate_delta(rate_pos[i], dir);
        int rr = r + rate_delta.first;
        int cc = c + rate_delta.second;

        if(rr<1 || rr>N || cc<1 || cc>N) {
            ret += rate_amount;
            continue;
        }
        b[rr][cc] += rate_amount;
    }

    int alpha_r = r + dr[dir];
    int alpha_c = c + dc[dir];
    if(alpha_r<1 || alpha_r>N || alpha_c<1 || alpha_c>N) {
        ret += alpha_amount;
    } else {
        b[alpha_r][alpha_c] += alpha_amount;
    }

    return ret;
}

Position get_next_pos(Position pos) {
    Position ret;
    int dir = pos.dir;
    int r = pos.r + dr[dir];
    int c = pos.c + dc[dir];
    ret.r = r;
    ret.c = c;

    if(r == c && dir == R) {
        ret.dir = U;
    } else if(r == c+1 && dir == L) {
        ret.dir = D;
    } else if(r+c == N+1 && (dir == U || dir == D)) {
        if(r > c) {
            ret.dir = R;
        } else {
            ret.dir = L;
        }
    } else {
        ret.dir = dir;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> b[i][j];
        }
    }

    Position pos = {N/2+1, N/2+1, L};
    int cnt = 0;
    while(cnt < N*N) {
        // pos.print_();
        // for(int i=1; i<=N; i++) {
        //     for(int j=1; j<=N; j++) {
        //         cout << b[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        ans += tornado(pos);
        pos = get_next_pos(pos);
        cnt++;
    }

    cout << ans;

    return 0;
}