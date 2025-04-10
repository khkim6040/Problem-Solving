#include <iostream>
#include <vector>



#define pii pair<int, int>
using namespace std;


int R, C, T;
int b[55][55];
int tmp[55][55];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// 공청기 위치, [air_pos, 0], [air_pos+1, 0]
int air_pos = -1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
        // (r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
        // 인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다. 
        // 확산되는 양은 Ar,c/5이고 소수점은 버린다. 즉, ⌊Ar,c/5⌋이다. (r, c)에 남은 미세먼지의 양은 Ar,c - ⌊Ar,c/5⌋×(확산된 방향의 개수) 이다.
    // 공기청정기가 작동한다. 공기청정기에서는 바람이 나온다.
        // 위쪽 공기청정기의 바람은 반시계방향으로 순환하고, 아래쪽 공기청정기의 바람은 시계방향으로 순환한다. 
        // 바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동한다. 
        // 공기청정기에서 부는 바람은 미세먼지가 없는 바람이고, 공기청정기로 들어간 미세먼지는 모두 정화된다.



    cin >> R >> C >> T;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            int x;
            cin >> x;
            b[i][j] = x;
            if(x==-1 && air_pos == -1) {
                air_pos = i;
            }
        }
    }

    while(T--) {
        // copy(&b[0][0], &b[0][0]+55*55, &tmp[0][0]);
        // 1. 미세먼지 확산 2 for
        // 먼지 위치 파악
        vector<pii> dusts;
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                if(b[i][j] > 0) {
                    dusts.push_back({i, j});
                }
            }
        }

        // 먼지 확산
        copy(&b[0][0], &b[0][0]+55*55, &tmp[0][0]);
        for(pii dust: dusts) {
            int r = dust.first;
            int c = dust.second;
            int spread = tmp[r][c]/5;
            // 사방 확인
            for(int i=0; i<4; i++) {
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr >= 0 && nr < R && nc >= 0 && nc < C && b[nr][nc] != -1) {
                    b[nr][nc] += spread;
                    b[r][c] -= spread;
                }
            }
        }
        
        
        
        // 2. 공청기 가동
        // 위쪽
        pii next = {air_pos, 1};
        copy(&b[0][0], &b[0][0]+55*55, &tmp[0][0]);
        tmp[air_pos][1] = 0;
        // 1 = right, 2 = up, 3 = left, 4 = down
        int flag = 1; 
        while(!(next.first == air_pos && next.second == 0)) {
            // move(next);
            int r = next.first;
            int c = next.second;
            int nr, nc;
            if (flag == 1) {
                // 오른쪽으로
                nr = r;
                nc = c + 1;
                if (nc == C-1) {
                    if(nr == 0) {
                        flag = 3;
                    } else {
                        flag = 2;
                    }
                }
            } else if (flag == 2) {
                // 위로
                nr = r - 1;
                nc = c;
                if (nr == 0) {
                    flag = 3;
                }
            } else if (flag == 3) {
                // 왼쪽으로
                nr = r;
                nc = c - 1;
                if (nc == 0) {
                    flag = 4;
                }
            } else if (flag == 4) {
                // 아래로
                nr = r + 1;
                nc = c;
            }

            // move b
            if(nr == air_pos && nc == 0) {
                break;
            }
            else {
                tmp[nr][nc] = b[r][c];
                next = {nr, nc};
            }
        }

        // 아래쪽
        next = {air_pos+1, 1};
        tmp[air_pos+1][1] = 0;
        // 1 = right, 2 = down, 3 = left, 4 = up
        flag = 1; 
        while(!(next.first == air_pos+1 && next.second == 0)) {
            // move(next);
            int r = next.first;
            int c = next.second;
            int nr, nc;
            if (flag == 1) {
                // 오른쪽으로
                nr = r;
                nc = c + 1;
                if (nc == C-1) {
                    if(nr == R-1) {
                        flag = 3;
                    } else {
                        flag = 2;
                    }
                }
            } else if (flag == 2) {
                // 아래로
                nr = r + 1;
                nc = c;
                if (nr == R-1) {
                    flag = 3;
                }
            } else if (flag == 3) {
                // 왼쪽으로
                nr = r;
                nc = c - 1;
                if (nc == 0) {
                    flag = 4;
                }
            } else if (flag ==4 ) {
                // 위로
                nr = r - 1;
                nc = c;
            }

            // move b
            if(nr == air_pos+1 && nc == 0) {
                break;
            }
            else {
                tmp[nr][nc] = b[r][c];
                next = {nr, nc};
            }
        }
        // 반영
        copy(&tmp[0][0], &tmp[0][0]+55*55, &b[0][0]);
    }


    int ans = 0;

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            ans += b[i][j];
        }
    }

    cout << ans+2;




    return 0;
}