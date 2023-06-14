#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using vvc = vector<vector<char>>;
int N, M;
vvc board;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
// red와 blue ball을 하나의 계로 보고 BFS 돌림
struct balls {
    int red_x, red_y;
    int blue_x, blue_y;
    int count;
    bool operator!= (const balls &other) const {
        return red_x!=other.red_x || red_y!=other.red_y || blue_x!=other.blue_x || blue_y!=other.blue_y;
    }
};

int push(balls &new_balls, const int &command) {
    // 상하좌우
    // board는 건드리지 않음
    new_balls.count++;
    bool red_in_hole = false;
    bool blue_in_hole = false;
    // 같은 위치에 있을 때 누가 먼저 도착했는지 분간하기 위함
    int red_origin_y = new_balls.red_y; 
    int red_origin_x = new_balls.red_x;
    int blue_origin_y = new_balls.blue_y; 
    int blue_origin_x = new_balls.blue_x; 

    while(board[new_balls.red_y+dy[command]][new_balls.red_x+dx[command]]!='#') {
        new_balls.red_y += dy[command];
        new_balls.red_x += dx[command];
        if(board[new_balls.red_y][new_balls.red_x]=='O') {
            red_in_hole = true;
        }
    }
    while(board[new_balls.blue_y+dy[command]][new_balls.blue_x+dx[command]]!='#') {
        new_balls.blue_y += dy[command];
        new_balls.blue_x += dx[command];
        if(board[new_balls.blue_y][new_balls.blue_x]=='O') {
            blue_in_hole = true;
        }
    }
    // 같은 위치에 있을 때 처리
    if(new_balls.red_x==new_balls.blue_x && new_balls.red_y==new_balls.blue_y) {
        if(command==0) {
            if(red_origin_y < blue_origin_y) 
                new_balls.blue_y++;
            else 
                new_balls.red_y++;
        }
        else if(command==1) {
            if(red_origin_y < blue_origin_y) 
                new_balls.red_y--;
            else 
                new_balls.blue_y--;
        }
        else if(command==2) {
            if(red_origin_x < blue_origin_x) 
                new_balls.blue_x++;
            else 
                new_balls.red_x++;
        }
        else if(command==3) {
            if(red_origin_x < blue_origin_x) 
                new_balls.red_x--;
            else 
                new_balls.blue_x--;
        }         
    }

    if(blue_in_hole) {
        return -1;
    }
    else {
        if(red_in_hole) {
            return 1;
        }
        else {
            return 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    board.assign(N, vector<char>());
    balls initial_balls;
    initial_balls.count = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            char x;
            cin >> x;
            board[i].push_back(x);
            // board에서 R, B를 지워 자유롭게 이동할 수 있게 함
            if(board[i][j]=='R') {
                initial_balls.red_y = i;
                initial_balls.red_x = j;
                board[i][j] = '.';
            }
            else if(board[i][j]=='B') {
                initial_balls.blue_y = i;
                initial_balls.blue_x = j;
                board[i][j] = '.';
            }
        }
    }
    // BFS
    queue<balls> q;
    bool red_in_hole = false;
    bool blue_in_hole = false;
    q.push(initial_balls);
    while(!q.empty() && q.front().count < 10) {
        int size = q.size();
        for(int i=0; i<size; i++) {
            balls cur = q.front();
            q.pop();
            for(int j=0; j<4; j++) {
                // 상하좌우 BFS
                balls new_balls = cur; 
                int res = push(new_balls, j);
                if(res==1) {
                    cout << new_balls.count;
                    return 0;
                }
                // blue가 안들어갔고, 두 공의 위치가 바뀌었을 때만 큐에 넣음
                else if(res==0 && new_balls!=cur){
                    q.push(new_balls);
                }
            }

        }
    }

    cout << -1;
    return 0;
}