#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

#define INF 2111111111

using namespace std;

struct Node {
    int idx;
    int cost;
    bool isReversed; // trap이 있는 노드는 반대의 가상의 선을 두어야 연결 가능
};

vector<vector<Node>> g;

bool isTrap[1005];
unordered_map<int, int> tMap; // Node index -> trap index

int dist[1005][1<<10]; // dist[i][j] = j state(=trap on/off 상태)에서 start에서 i까지 가는 최단거리


struct QNode {
    int idx;
    int cost;
    int state;
    
    const bool operator< (const QNode& other) const {
        return cost > other.cost;
    }
};

priority_queue<QNode> pq;

int N;

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    N = n;
    int answer = INF;
    
    g.assign(N+1, vector<Node>());
    
    for(int i=0; i<traps.size(); i++) {
        int t = traps[i];
        isTrap[t] = true;
        tMap[t] = i;
    }
    
    for(vector<int> road: roads) {
        int from = road[0];
        int to = road[1];
        int cost = road[2];
        
        g[from].push_back({to, cost, false});
        g[to].push_back({from, cost, true});
    }
    
    for(int i=1; i<=N; i++) {
        for(int j=0; j<(1<<10); j++) {
            dist[i][j] = INF;
        }
    }
    dist[start][0] = 0;
    
    
    pq.push({start, 0, 0});
    while(!pq.empty()) {
        QNode cur = pq.top();
        pq.pop();
        
        int idx = cur.idx;
        int cost = cur.cost;
        int state = cur.state;
        
        if(idx == end) {
            answer = cost;
            break;
        }
        
        bool isCurActivated = false;
        if(isTrap[idx] && !(state & (1<<tMap[idx]))) isCurActivated = true;
        if(isTrap[idx]) state ^= (1<<tMap[idx]);
        
        // cout << idx << ' ' << cost << ' ' << state <<' '  << isCurActivated <<  '\n';
        for(Node next: g[idx]) {
            int nIdx = next.idx;
            int nCost = next.cost;
            bool isReversed = next.isReversed;
            
            
            
            bool isNextActivated = false;
            if(isTrap[nIdx] && (state & (1<<tMap[nIdx]))) isNextActivated = true;
            
            // cout << nIdx << ' ' << nCost << ' ' << isReversed << ' '<<  isNextActivated << '\n';
            
            
            // 4가지 경우
            // 둘 다 발동 X or 둘 다 발동 O
                // !isReversed 일 때 건널 수 있음
            // 둘 중 하나만 발동 시
                // isReversed 일 때 건널 수 있음
            
            if(isCurActivated == isNextActivated) {
                if(isReversed) continue;
                
                if(dist[nIdx][state] > cost + nCost) {
                    dist[nIdx][state] = cost + nCost;
                    pq.push({nIdx, cost+nCost, state});
                }
                
            } else {
                if(!isReversed) continue;
                
                if(dist[nIdx][state] > cost + nCost) {
                    dist[nIdx][state] = cost + nCost;
                    pq.push({nIdx, cost+nCost, state});
                }
                
            }
            
        }
        
        cout << '\n';
        
    }
   
    
    return answer;
}







