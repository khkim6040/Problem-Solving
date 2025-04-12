// 첫째 줄에 N, M, T이 주어진다.

// 둘째 줄부터 N개의 줄에 원판에 적힌 수가 주어진다. i번째 줄의 j번째 수는 (i, j)에 적힌 수를 의미한다.

// 다음 T개의 줄에 xi, di, ki가 주어진다.

#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>

using namespace std;

int N, M, T;
int total, total_records;

int b[55][55];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs(int row, int col) {
    queue<pii> q;
    q.push({row, col});

    bool is_first = true;
    int target = b[row][col];

    while(!q.empty()) {
        auto [pr, pc] = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int r = pr + dr[i];
            int c = pc + dc[i];

            if(r>=0 && r<N && b[r][(c+M)%M] == target) {
                // cout << target << ' ' << r << ' ' << c << '\n';
                q.push({r, (c+M)%M});
                total -= b[r][(c+M)%M];
                total_records--;
                b[r][(c+M)%M] = -1;
                if (is_first) {
                    // cout << "isfirst\n";
                    // cout << target << ' ' << pr << ' ' << pc << '\n';

                    total -= b[pr][pc];
                    total_records--;
                    is_first = false;
                    b[pr][pc] = -1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> T;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int x;
            cin >> x;
            b[i][j] = x;
            total += x;
            total_records++;
        }
    }


    while(T--) {
        int X, D, K;
        cin >> X >> D >> K;

        // Rotate
        int tmp[55][55];
        copy(&b[0][0], &b[54][54], &tmp[0][0]);

        for(int i=0; i<N; i++) {
            if((i+1)<X || (i+1)%X != 0) continue;

            int gap = K%M;
            if (D) {
                gap = M-gap;
            }

            for(int j=0; j<M; j++) {
                tmp[i][(j+gap)%M] = b[i][j];
            }
        }
        copy(&tmp[0][0], &tmp[54][54], &b[0][0]);


        // for(int i=0; i<N; i++) {
        //     for(int j=0; j<M; j++) {
        //         cout << b[i][j] << ' '; 
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        // Delete
        int prev_total = total;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(b[i][j] == -1) continue;
                bfs(i, j);
            }
        }

        // Modify by avg
        if(prev_total == total && total > 0 && total_records > 0) {
            int avg = total/total_records;
            int is_frac = total%total_records;

            for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {
                    if(b[i][j] == -1) continue;

                    if(b[i][j] > avg) {
                        b[i][j]--;
                        total--;
                    } else if(b[i][j] < avg) {
                        b[i][j]++;
                        total++;
                    } else if(is_frac) {
                        b[i][j]++;
                        total++;
                    }
                }
            }
        }
    }


    // for(int i=0; i<N; i++) {
    //     for(int j=0; j<M; j++) {
    //         cout << b[i][j] << ' '; 
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    cout << total;

    return 0;
}