#include <string>
#include <vector>

using namespace std;

// 세 개 모두 리프
// 두 개 리프, 하나는 내부

// 아무데서나 dfs -> 가장 멀리 떨어진 노드(A)
// A에서 dfs -> 가장 멀리 떨어진 노드(B), 두 번째로 먼 노드(C)


vector<vector<int>> g;
int N;
int maxIdx;
int secondMaxIdx;
int maxDist;
int secondMaxDist;

void dfs(int cur, int parent, int dist) {
    if(dist >= maxDist) {
        secondMaxDist = maxDist;
        maxDist = dist;
        maxIdx = cur;
    }
    
    for(int next: g[cur]) {
        if(next == parent) continue;
        
        dfs(next, cur, dist+1);
    }
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    N = n;
    
    g.assign(N+1, vector<int>());
    
    for(auto edge: edges) {
        g[edge[0]].push_back(edge[1]);
        g[edge[1]].push_back(edge[0]);
    }

    dfs(1, -1, 0);
    
    int A = maxIdx;
    secondMaxDist = 0;
    maxDist = 0;
    maxIdx = 0;
    dfs(A, -1, 0);

    int B = maxIdx;
    int candi1 = secondMaxDist;
    
    secondMaxDist = 0;
    maxDist = 0;
    maxIdx = 0;
    
    dfs(B, -1, 0);
    
    int candi2 = secondMaxDist;
    
    
    
    return max(candi1, candi2);
}