#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int M, N, H;
int tomatoes[102][102][102];
queue<tuple<int, int, int>> bfs_queue;
int dz[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, 0, -1, 1};
int unripe_tomatoes = 0;

int RipenTomatoesWithBfs() {
    int days = -1;
    //큐가 비어있으면(=익힐 토마토 없으면) 탈출
    while(bfs_queue.size() > 0) {
        int size = bfs_queue.size();
        days++;
        for(int i=0; i<size; i++) {
            tuple<int, int, int> cur_point = bfs_queue.front();
            bfs_queue.pop();
            for(int j=0; j<6; j++) {
                int z = get<0>(cur_point) + dz[j];
                int y = get<1>(cur_point) + dy[j];
                int x = get<2>(cur_point) + dx[j];
                if(z>=0 && y>=0 && x>=0 && z<H && y<N && x<M && tomatoes[z][y][x] == 0) {
                    tomatoes[z][y][x] = 1;
                    bfs_queue.push(make_tuple(z, y, x));
                    unripe_tomatoes--;
                }
            }
        }
    }
    
    return days;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> H;
    //입력
    for(int i=0; i<H; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<M; k++) {
                cin >> tomatoes[i][j][k];
                if(tomatoes[i][j][k] == 0) {
                    unripe_tomatoes++;
                }
                else if(tomatoes[i][j][k] == 1) {
                    bfs_queue.push(make_tuple(i, j, k));
                }
            }
        }
    }
    //안익은 토마토가 없을 때 && 익은 토마토가 하나 이상일 때 -> 모든 토마토가 익어있을 때
    if(unripe_tomatoes == 0 && bfs_queue.size()>0) {
        cout << 0;
        return 0;
    }
    //토마토 익히기
    int result = RipenTomatoesWithBfs();
    
    //덜익은 토마토가 있다면
    if(unripe_tomatoes>0) {
        cout << -1;
    }
    else {
        cout << result;
    }
    
    return 0;
}