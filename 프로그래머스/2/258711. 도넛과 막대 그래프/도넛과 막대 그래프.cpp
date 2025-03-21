#include <string>
#include <vector>
#include <iostream>

#define SIZE 1000005
using namespace std;

vector<vector<int>> g(SIZE, vector<int>());
vector<int> answer(4);
int in_order[SIZE];
int out_order[SIZE];
bool visited[SIZE];


void dfs(int cur) {
    if(visited[cur]) {
        if(out_order[cur] == 2) {
            answer[3]++;
            return;
        } else if (out_order[cur] == 1) {
            answer[1]++;
            return;
        }
    } else {
        visited[cur] = true;        
        if(out_order[cur] == 2) {
            answer[3]++;
            return;
        } else if(out_order[cur]==0) {
            answer[2]++;
            return;
        }
        dfs(g[cur][0]);
    }
}

vector<int> solution(vector<vector<int>> edges) {
    int N = edges.size();
    for(auto edge: edges) {
        int s = edge[0];
        int e = edge[1];
        
        g[s].push_back(e);
        in_order[e]++;
        out_order[s]++;
    }
    // find 단절점
    for(int i=1; i<=SIZE; i++) {
        if(in_order[i]) continue;
        if(out_order[i] >= 2) {
            answer[0] = i;
            break;
        }
    }
    
    for(int node: g[answer[0]]) {
        dfs(node);
    }
    
    
    
    
    return answer;
}