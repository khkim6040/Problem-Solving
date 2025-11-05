#include <string>
#include <vector>
#include <iostream>

#define NO 'x'
using namespace std;

char b[53][53];
bool visited[55][55];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int N, M;
int answer;

void dfs(int pr, int pc, int target) {
    // cout << pr << ' ' << pr << '\n';
    visited[pr][pc] = true;
    
    for(int i=0; i<4; i++) {
        int r = pr+dr[i];
        int c = pc+dc[i];
        if(r<0 || r>N+1 || c<0 || c>M+1 || visited[r][c]) continue;
        if(b[r][c] == NO) {
            dfs(r, c, target);
        } else if(b[r][c] == target) {
            answer--;
            b[r][c] = NO;
            visited[r][c] = true;
        } 
    }
}

void erase(char target) {
    for(int i=0; i<N+2; i++) {
        for(int j=0; j<M+2; j++) {
            if(b[i][j] == target && !visited[i][j]) {
                visited[i][j] = true;
                answer--;
                b[i][j] = NO;
            }
        }
    }
}

void clearB() {
    for(int i=0; i<N+2; i++) {
        for(int j=0; j<M+2; j++) {
            visited[i][j] = false;
        }
    }
}


int solution(vector<string> storage, vector<string> requests) {
    
    N = storage.size();
    M = storage[0].size();
    answer = N*M;
    
    fill_n(&b[0][0], 53*53, NO);
    
    for(int i=0; i<N; i++) {
        string s = storage[i];
        for(int j=0; j<M; j++) {
            char c = s[j];
            b[i+1][j+1] = c;
        }
    }
    
    for(string req: requests) {
        clearB();
        char c = req[0];
        if(req.size() == 1) {
            dfs(0, 0, c);
        } else {
            erase(c);
            
        }
    }
    return answer;
}