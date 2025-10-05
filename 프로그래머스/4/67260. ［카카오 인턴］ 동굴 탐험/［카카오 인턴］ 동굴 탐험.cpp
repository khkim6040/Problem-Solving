#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

// 빗금 => from, 색칠 => to
// 0에서 탐색하면서 빗금인 노드를 찾음
// 빗금인 노드를 못 찾으면 false
// 빗금인 노드를 찾으면 대응하는 색칠노드 일반으로 바꾸고 다시 탐색
// 최대 O(N*(N/2)) 이라 시간초과날듯

// 모든 빗금 노드에서 위로 올라가면서 만나는 색칠 노드 정보 파악하기?
// 모든 빗금 노드가 위로 올라가면서 만나는 색칠 노드가 없다면 true
// for idx: 빗금노드 
    // block[idx].push_back(색칠노드)
// for idx: 빗금노드
    // if block[idx].size() == 0
        // isClear[map[idx]] = true // 대응되는 색칠노드 이동 가능하게 변경
// 이 방법도 지웠다가 모든 빗금노드 다시 보고 반복이 좀 있을 듯

// queue<int> q
// q.push(0)
// while(!q.empty())
    // 0에서 "도달 가능한 노드" 파악
    // int idx = q.front()
    // dfs(idx)
    // 색칠 노드라면 거기서 stop, 만나는 빗금 노드 정보 저장
    // 다 탐색한 후 foreach idx: 만났던 빗금 노드들
        // cnt++;
        // mappedIdx = mapper[idx] // 대응되는 색칠 노드가 도달 가능했는지 파악
        // 도달 가능하다면 그 색칠 노드 아래로 진행 가능한 것이기 때문에 다시 진행하면서 빗금 노드 찾고.. 반복
        // if(visited[mappedIdx])
            // q.push(mappedIdx)

// if cnt == order.size()
    // true

vector<vector<int>> g;
unordered_map<int, int> mapper;
queue<int> dashedNodes;
bool isDashed[200005];
bool isColored[200005];
bool visited[200005]; // 0에서 reachable 한지도 저장
int parent[200005];

void labelParents(int cur, int p) {
    parent[cur] = p;
    
    for(int next: g[cur]) {
        if(next == p) continue;
        labelParents(next, cur);
    }
}

void dfs(int cur) {
    if(isDashed[cur] && !visited[cur]) {
        dashedNodes.push(cur);
    }
    
    visited[cur] = true;
    if(isColored[cur]) return;
    
    for(int next: g[cur]) {
        if(next == parent[cur]) continue;
        dfs(next);
    }
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = false;
    
    g.assign(n, vector<int>());
    for(vector<int> p: path) {
        int from = p[0];
        int to = p[1];
        g[from].push_back(to);
        g[to].push_back(from);
    }
    
    labelParents(0, -1);
    
    for(vector<int> o: order) {
        isDashed[o[0]] = true;
        isColored[o[1]] = true;
        mapper[o[0]] = o[1];
    }
    
    queue<int> q;
    q.push(0);
    int cnt = 0;
    while(!q.empty()) {
        // 0에서 "도달 가능한 노드" 파악
        int idx = q.front();
        q.pop();

        dfs(idx);
        // 색칠 노드라면 거기서 stop, 만나는 빗금 노드 정보 저장
        // 다 탐색한 후 foreach idx: 만났던 빗금 노드들
        while(!dashedNodes.empty()) {
            int idx = dashedNodes.front();
            dashedNodes.pop();
            cnt++;
            int mappedIdx = mapper[idx]; // 대응되는 색칠 노드가 도달 가능했는지 파악
            isColored[mappedIdx] = false;
            // 도달 가능하다면 그 색칠 노드 아래로 진행 가능한 것이기 때문에 다시 진행하면서 빗금 노드 찾고.. 반복
            if(visited[mappedIdx]) {
                q.push(mappedIdx);
            }
        }
    }


    if (cnt == order.size()) {
        answer = true;        
    }
    
    return answer;
}