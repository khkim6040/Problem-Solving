#include <string>
#include <vector>
#include <queue>

#define pii pair<int, int>
using namespace std;

int N;

vector<vector<pii>> puzzles;
bool used[3000];
bool visited[55][55];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};


bool find(vector<pii> vec) {
    int vecSize = vec.size();
    int total = puzzles.size();
    for(int j=0; j<total; j++) {
        if(used[j]) continue;
        vector<pii> puzzle = puzzles[j];
        int size = puzzle.size();
        if(size != vecSize) continue;
        
        int flag = true;
        for(int i=0; i<size; i++) {
            if(vec[i].first != puzzle[i].first || vec[i].second != puzzle[i].second) {
                flag = false;
                break;
            }
        }
        
        if(flag) {
            used[j] = true;
            return true;
        }
    }
    
    return false;
}

vector<vector<int>> rotate(vector<vector<int>> b) {
    vector<vector<int>> temp = b;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            temp[i][j] = b[N-j-1][i];
        }
    }
    
    return temp;
}

vector<pii> getShape(int& pr, int& pc, vector<vector<int>>& b, int isTable) {
    vector<pii> ret;
    ret.push_back({0, 0});
    visited[pr][pc] = true;
    
    queue<pii> q;
    q.push({pr, pc});
    while(!q.empty()) {
        pii cur = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int r = cur.first + dr[i];
            int c = cur.second + dc[i];
            if(r<0 || r>=N || c<0 || c>= N || b[r][c] != isTable || visited[r][c]) continue;
            q.push({r, c});
            visited[r][c] = true;
            ret.push_back({r-pr, c-pc});
        }
    }
    
    return ret;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    N = game_board.size();
    // for i
        // for j
            // 퍼즐 모양 저장 (첫 번째 만난 지점부터 deterministic하게 탐색)
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(table[i][j] == 1 && !visited[i][j]) {
                vector<pii> shape = getShape(i, j, table, 1);
                puzzles.push_back(shape);
            }
        }
    }

    for(int k=0; k<4; k++) {
        // game_board 4방향 돌려가면서 맞는 퍼즐 있는지 판단
        fill_n(&visited[0][0], 55*55, false);
        vector<vector<int>> temp = game_board;
        game_board = rotate(temp);
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(game_board[i][j] == 0 && !visited[i][j]) {
                    vector<pii> shape = getShape(i, j, game_board, 0);
                    if(find(shape)) {
                        answer += shape.size();
                        // fill one
                        for(pii p: shape) {
                            game_board[i+p.first][j+p.second] = 1;
                        }
                    }
                }
            }
        }
    }
        
    return answer;
}