#include <string>
#include <vector>
#include <iostream>

#define pii pair<int, int>
using namespace std;



int dc[][3] = {{0, 1, 2}, {0, 1, 0}, {-1, 0, 0}, {-1, 0, 1}, {-2, -1, 0}};
int FAIL = 0;
int SUCCESS = 1;
int SKIP = 2;
int SKIPNUM = 500;

int b[55][55];
bool visited[205];
bool consumed[205];
vector<vector<pii>> blocks;

int TRYPREVIOUS = -2;
int NONE = -1;

void getShape(int i, int j, int m) {
    vector<pii> block;
    // 빨강
    // [i][j+1], [i][j+2], [i+1][j+2] / j, j+1, j+2
    if(b[i][j+1] == m && b[i][j+2] == m && b[i+1][j+2] == m) {
        return;
    }
    // [i][j+1], [i+1][j], [i+2][j] / j, j+1
    if(b[i][j+1] == m && b[i+1][j] == m && b[i+2][j] == m) {
        return;
    }
    // [i+1][j], [i+1][j+1], [i+1][j+2] / [i][j+1], [i][j+2]
    if(b[i+1][j] == m && b[i+1][j+1] == m && b[i+1][j+2] == m) {
        block.push_back({TRYPREVIOUS, 2});
        block.push_back({i+1, j+1});
        block.push_back({i+1, j+2});
        
        block.push_back({i, j});
        block.push_back({i+1, j});
        blocks.push_back(block);
        return;
    }
    // [i+1][j], [i+2][j], [i+2][j-1] / [i][j-1], [i+1][j-1]
    if(b[i+1][j] == m && b[i+2][j] == m && j-1>=0 && b[i+2][j-1] == m) {
        block.push_back({NONE, 1});
        block.push_back({i+2, j-1});
        
        block.push_back({i, j});
        block.push_back({i+1, j});
        block.push_back({i+2, j});
        blocks.push_back(block);
        return;
    }
    // 주황
    // [i][j+1], [i][j+2], [i+1][j] / j, j+1, j+2
    if(b[i][j+1] == m && b[i][j+2] == m && b[i+1][j] == m) {
        return;
    }
    // [i+1][j], [i+2][j], [i+2][j+1] / [i][j+1], [i+1][j+1]
    if(b[i+1][j] == m && b[i+2][j] == m && b[i+2][j+1] == m) {
        block.push_back({NONE, 1});
        block.push_back({i+2, j+1});
        
        block.push_back({i, j});
        block.push_back({i+1, j});
        block.push_back({i+2, j});
        blocks.push_back(block);
        return;
    }
    // [i+1][j], [i+1][j-1], [i+1][j-2] / [i][j-1], [i][j-2]
    if(b[i+1][j] == m && j-2>=0 && b[i+1][j-1] == m && b[i+1][j-2] == m) {
        block.push_back({TRYPREVIOUS, 2});
        block.push_back({i+1, j-1});
        block.push_back({i+1, j-2});
        
        block.push_back({i, j});
        block.push_back({i+1, j});
        blocks.push_back(block);
        return;
    }
    // [i][j+1], [i+1][j+1], [i+2][j+1] / j, j+1
    if(b[i][j+1] == m && b[i+1][j+1] == m && b[i+2][j+1] == m) {
        return;
    }
    // 하늘
    // [i+1][j], [i+1][j-1], [i+1][j+1] / [i][j-1], [i][j+1]
    if(b[i+1][j] == m && j-1>=0 && b[i+1][j-1] == m && b[i+1][j+1] == m) {
        block.push_back({TRYPREVIOUS, 2});
        block.push_back({i+1, j-1});
        block.push_back({i+1, j+1});
        
        block.push_back({i, j});
        block.push_back({i+1, j});
        blocks.push_back(block);
        return;
    }
    // [i+1][j], [i+1][j+1], [i+2][j] / j, j+1
    if(b[i+1][j] == m && b[i+1][j+1] == m && b[i+2][j] == m) {
        return;
    }
    // [i][j+1], [i][j+2], [i+1][j+1] / j, j+1, j+2
    if(b[i][j+1] == m && b[i][j+2] == m && b[i+1][j+1] == m) {
        return;
    }
    // [i+1][j-1], [i+1][j], [i+2][j] / j-1, j
    if(j-1>=0 && b[i+1][j-1] == m && b[i+1][j] == m && b[i+2][j] == m) {
        return;
    }
    
    cout << i << ' ' << j << ' ' << m << '\n';
    return;
}

bool check(vector<pii> block) {
    bool ret = true;
    int size = block[0].second;
    for(int i=1; i<1+size; i++) {
        pii p = block[i];
        int r = p.first;
        int c = p.second;
        int num = b[r][c];
        for(int i=r; i>=0; i--) {
            if(!(b[i][c] == 0 || b[i][c] == num)) {
                // cout << "CHECK: " << i << ' ' << c << '\n';
                ret = false;
                break;
            }
        }
    }
    
    return ret;
}



int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = board.size();
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            b[i][j] = board[i][j];
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int color = b[i][j];
            
            if(color > 0 && !visited[color]) {
                visited[color] = true;
                getShape(i, j, color);
            }
        }
    }
    
    int size = blocks.size();
    for(int i=0; i<size; i++) {
        if(consumed[i]) continue;
        vector<pii> block = blocks[i];
        int tryPrevious = false;
        // cout << i << '\n';
        // cout << block[0].first << ' '  << block[0].second << ' ';
        // cout << block[1].first << ' '  << block[1].second << ' ';
        // cout << block[2].first << ' '  << block[2].second << ' ';
        // cout << block[3].first << ' '  << block[3].second << ' ';
        // cout << block[4].first << ' '  << block[4].second << ' ';
        cout << '\n';
        if(check(block)) {
            // cout << "PASSED: " << i << '\n';
    
            answer++;
            tryPrevious = block[0].first;
            for(pii p: block) {
                if(p.second == -1) continue;
                b[p.first][p.second] = 0;   
            }
        }
        
        if(tryPrevious) {
            consumed[i] = true;
            i = max(i-2, -1);
        }
    }
    
    return answer;
}