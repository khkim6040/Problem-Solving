#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define pii pair<int, int>

using namespace std;

vector<vector<pii>> g; // {cost, idx}

bool isGate[50005];
bool isSummit[50005];

int dist[50005];

vector<pii> answers;

vector<int> solution(int N, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    // 가상의 0번 노드 -> gates 각각 비용 0으로 연결     
    // 0번에서 다익스트라
    // summits들 중 가중치 가장 작고, 그 중 인덱스 가장 작은거 선택
    
    
    g.assign(N+1, vector<pii>());
    fill_n(dist, N+1, 111111111111111);
    dist[0] = 0;
    for(auto p: paths) {
        int from = p[0];
        int to = p[1];
        int cost = p[2];
        g[from].push_back({cost, to});
        g[to].push_back({cost, from});
    }
    for(int gate: gates) {
        isGate[gate] = true;
        
        g[0].push_back({0, gate}); // 가상의 노드 0과 gate 연결
    }
    for(int s: summits) {
        isSummit[s] = true;
    }
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    
    while(!pq.empty()) {
        pii p = pq.top();
        pq.pop();
        int cost = p.first;
        int cur = p.second;
        
        for(pii next: g[cur]) {
            if(dist[next.second] > max(next.first, cost)) {
                dist[next.second] = max(next.first, cost);
                if(!isSummit[next.second]) {
                    pq.push({dist[next.second], next.second});    
                }
            }
        }
    }
    
    int minVal = 2111111111;
    int idx = -1;
    for(int s: summits) {
        if(dist[s] < minVal) {
            minVal = dist[s];
            idx = s;
        } else if(dist[s] == minVal && s < idx) {
            idx = s;
        } 
    }
    
    answer.push_back(idx);
    answer.push_back(minVal);
    return answer;
}