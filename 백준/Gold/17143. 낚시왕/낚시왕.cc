// 첫째 줄에 격자판의 크기 R, C와 상어의 수 M이 주어진다. (2 ≤ R, C ≤ 100, 0 ≤ M ≤ R×C)
// 둘째 줄부터 M개의 줄에 상어의 정보가 주어진다. 상어의 정보는 다섯 정수 r, c, s, d, z (1 ≤ r ≤ R, 1 ≤ c ≤ C, 0 ≤ s ≤ 1000, 1 ≤ d ≤ 4, 1 ≤ z ≤ 10000) 로 이루어져 있다. 
// 두 상어가 같은 크기를 갖는 경우는 없고, 하나의 칸에 둘 이상의 상어가 있는 경우는 없다.

// 낚시왕이 오른쪽으로 한 칸 이동한다.
// 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
// 상어가 이동한다.

#include <iostream>

#define NO -1
using namespace std;

int R, C, M;

struct Shark{
    int s;
    int d;
    int z;
};

Shark b[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> M;

    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            b[i][j] = {NO, NO, NO};
        }
    }

    for(int i=0; i<M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        b[r][c] = {s, d, z};
    }

    // for(int i=1; i<=R; i++) {
    //     for(int j=1; j<=C; j++) {
    //         cout << b[i][j].z << ' '; 
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    int ans = 0;
    for(int c=1; c<=C; c++) {
        int r = 1;
        while(b[r][c].s == NO && r<=R) {
            r++;
        }
        // 상어 잡기
        if (r <= R) {
            // cout << r << ' ' << c << ' ' << b[r][c].z << '\n';
            ans += b[r][c].z;
            b[r][c] = {NO, NO, NO};
        }
        // 상어 이동
        Shark tmp[105][105];
        fill_n(&tmp[0][0], 105*105, Shark{NO, NO, NO});
        for(int i=1; i<=R; i++) {
            for(int j=1; j<=C; j++) {
                if(b[i][j].s == NO) continue;

                int s = b[i][j].s;
                int d = b[i][j].d;
                int z = b[i][j].z;
                // (r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기이다. d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.
                int amount;
                int nr = i;
                int nc = j;
                // cout << z << '\n';
                // cout << " i: " << i << " j: " << j << " s: " << s << " d: " << d << '\n';
                if(d == 1) {
                    // up
                    amount = (s+(R-i))%(2*(R-1));
                    if(amount <= R-1) {
                        nr = R-amount;
                        if(s>0 && amount==0) {
                            d = 2;
                        }
                    } else {
                        nr = 1+(amount-(R-1));
                        d = 2;
                    }

                    // if(s>i-1) d = 2;
                } else if(d == 2) {
                    // down
                    amount = (s+(i-1))%(2*(R-1));
                    if(amount <= R-1) {
                        nr = 1+amount;
                        if(s>0 && amount==0) {
                            d = 1;
                        }
                    } else {
                        nr = R-(amount-(R-1));
                        d = 1;
                    }

                    // if(s>R-i) d = 1;
                } else if(d == 3) {
                    // right
                    amount = (s+(j-1))%(2*(C-1));
                    if(amount <= C-1) { 
                        nc = 1+amount;
                        if(s>0 && amount==0) {
                            d = 4;
                        }
                    } else {
                        nc = C-(amount-(C-1));
                        d = 4;
                    }

                    // if(s>C-j) d = 4;
                } else if(d == 4) {
                    // left
                    amount = (s+(C-j))%(2*(C-1));
                    if(amount <= C-1) { 
                        nc = C-amount;
                        if(s>0 && amount==0) {
                            d = 3;
                        }
                    } else {
                        nc = 1+(amount-(C-1));
                        d = 3;
                    }

                    // if(s>j-1) d = 3;
                }
                if((tmp[nr][nc].s == NO) || (tmp[nr][nc].z < z)) {
                    tmp[nr][nc] = {s, d, z};
                } 
            }
        }

        copy(&tmp[0][0], &tmp[104][104], &b[0][0]);
        // for(int i=1; i<=R; i++) {
        //     for(int j=1; j<=C; j++) {
        //         cout << b[i][j].z << ' '; 
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }

    cout << ans;


    return 0;
}