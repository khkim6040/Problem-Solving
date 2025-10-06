#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

int N;
int H;

bool visited[304][304];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

struct DSU {
    vector<vector<int>> parent;
    vector<vector<int>> b;
    
    DSU(int n, vector<vector<int>> board) {
        parent.assign(n, vector<int>(n));
        b = board;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                parent[i][j] = n*i + j;
            }
        }
    }
    
    int find(int i, int j) {
        int p = parent[i][j];
        int r = p/N;
        int c = p%N;
        if(r==i && c==j) return p;
        
        return parent[i][j] = find(r, c);
    }
    
    void merge(int r1, int c1, int r2, int c2) {
        int p1 = find(r1, c1);
        int p2 = find(r2, c2);
        
        if(p1 > p2) {
            swap(p1, p2);
        }
        
        parent[p2/N][p2%N] = p1;
    }
    
    void dfs(int pr, int pc) {
        visited[pr][pc] = true;
        
        for(int i=0; i<4; i++) {
            int r = pr + dr[i];
            int c = pc + dc[i];
            if(r>=0 && r<N && c>=0 && c<N && !visited[r][c] && abs(b[pr][pc]-b[r][c]) <= H) {
                merge(pr, pc, r, c);
                dfs(r, c);
            }
        }
    }
    
    void print_() {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cout << parent[i][j] << ' ';
            }
            cout << '\n';
        }
    }
};

struct Node {
    int h;
    int a;
    int b;
    
    bool operator< (const Node& other) const {
        return h > other.h;
    }
    
    void print_() {
        cout << h << ' ' << a << ' ' << b <<'\n';
    }
};

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    H = height;
    N = land.size();
    DSU d = DSU(N, land);
    // height 안으로 갈 수 있는 곳들 구역 나누기
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!visited[i][j]) {
                d.dfs(i, j);
            }
        }
    }
    // d.print_();
    
    // 모든 칸 돌면서 한 구역에서 다른 구역으로 가는 높이 차이 담는 배열 오름차순 우선순위 큐
    priority_queue<Node> pq;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int p1 = d.find(i, j);
            int h1 = land[i][j];
            for(int k=0; k<4; k++) {
                int r = i + dr[k];
                int c = j + dc[k];
                // 높이가 높아질 때만 고려해서 같은 부분 중복 계산 방지
                if(r>=0 && r<N && c>=0 && c<N) {
                    int p2 = d.find(r, c);
                    int h2 = land[r][c];
                    if(p1 == p2) continue;
                    if(h1 < h2) {
                        pq.push({h2-h1, p1, p2});    
                    }
                }
            }
        }
    }
    
    // 큐 계속 털면서 이어지지 않은 구역 있다면 연결 후 사용한 사다리 카운트(구역 개수-1개 사용하면 끝)
    int cnt = 0;
    while(!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        // cur.print_();
        
        int p1 = cur.a;
        int r1 = p1/N;
        int c1 = p1%N;
        int p2 = cur.b;
        int r2 = p2/N;
        int c2 = p2%N;
        p1 = d.find(r1, c1);
        p2 = d.find(r2, c2);
        
        if(p1 == p2) continue;
        
        answer += cur.h;
        d.merge(r1, c1, r2, c2);
    }
        // O(N*N*logN)
        // Union Find merge

    
    return answer;
}