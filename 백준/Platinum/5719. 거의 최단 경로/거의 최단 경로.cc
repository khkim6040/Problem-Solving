#include <iostream>
#include <vector>
#include <queue>
#define INF 2111111111
using namespace std;
struct Node {
    int index;
    int cost;
    bool operator< (const Node &other) const {
        return cost > other.cost;
    }
};
int N, M, S, D;
vector<vector<Node>> graph;
vector<vector<int>> parent;
bool deleted[505][505];
// flag = 최단거리 간선 제거 여부
int findShortestPath(int start, bool flag) {
    int dist[505];
    fill(dist, dist+505, INF);
    priority_queue<Node> pq;
    pq.push({start, 0});
    dist[start] = 0;
    while(!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        for(auto next: graph[cur.index]) {
            if(deleted[cur.index][next.index]) continue;
            // 최단거리 간선 제거 이전에는 가능한 모든 최단거리를 뽑아내기 위해 거리 비교식 <= 에서도 간선 저장해야 함, parent를 2차원 배열로 선언
            if(dist[cur.index]+next.cost <= dist[next.index]) {
                if(flag == false) {
                    if(dist[cur.index]+next.cost == dist[next.index]) {
                        parent[next.index].push_back(cur.index);
                        // pq에 쓸데없는 노드 안넣기 위해 거리가 같다면 parent만 넣고 countinue
                        continue;                        
                    }
                    // 최단거리 갱신되는 간선 들어오면 이전의 parent는 지워줘야 함
                    parent[next.index].clear();
                    parent[next.index].push_back(cur.index);
                }
                // 최단거리 간선 제거한 후에는 거리 같은거 업데이트하지 않아야함
                else if(flag == true && dist[cur.index]+next.cost == dist[next.index]) {
                    continue;   
                }
                // 공통적으로 다익스트라
                dist[next.index] = dist[cur.index]+next.cost;
                next.cost = dist[next.index];
                pq.push(next);  
            }
        }
    }
    return dist[D];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(true) {
        cin >> N >> M;
        if(N+M==0) {
            break;
        }
        cin >> S >> D;  
        graph.assign(N, vector<Node>());
        parent.assign(505, vector<int>());
        fill(&deleted[0][0], &deleted[504][505], false);
        for(int i=0; i<M; i++) {
            int s, e, c;
            cin >> s >> e >> c;
            graph[s].push_back({e, c});
        }

        int pre_delete = findShortestPath(S, false);
        if(pre_delete==INF) {
            cout << -1 << '\n';
            continue;
        }
        // 최단거리 하나 이상일 수 있으므로 가능한 모든 최단거리 삭제 작업
        bool visited[505] = {0, };
        queue<int> q;
        q.push(D);
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                int cur = q.front();
                q.pop();
                if(visited[cur]) continue;
                visited[cur] = true;
                for(int pre: parent[cur]) {
                    if(!deleted[pre][cur]) {
                        deleted[pre][cur] = true;
                        q.push(pre);
                    }
                }
            }
        }

        int after_delete = findShortestPath(S, true);
        if(after_delete==INF) {
            cout << -1 << '\n';
        }
        else {
            cout << after_delete << '\n';
        }
    }   

    return 0;
}