#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2111111111
using namespace std;
struct Node {
    int index;
    int cost;
    bool operator< (const Node &other) const {
        return cost > other.cost;
    }
};

int N, M, A, B;
vector<vector<Node>> graph;
int dist[1005];
bool visited[1005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    graph.assign(N+1, vector<Node>());
    for(int i=0; i<M; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        graph[s].push_back({e, c});
    }
    cin >> A >> B;
    // 같은 간선 여러 개일 때 오름차순 정렬함으로써 pq 시간복잡도 줄여 시간초과 피함
    for(int i=0; i<graph.size(); i++) {
        sort(graph[i].rbegin(), graph[i].rend());
    }
    // dijkstra
    fill(dist, dist+1005, INF);
    priority_queue<Node> pq;
    pq.push({A, 0});
    dist[A] = 0;
    while(!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        visited[cur.index] = true;
        for(Node next: graph[cur.index]) {
            if(!visited[next.index] && dist[next.index] > dist[cur.index]+next.cost) {
                dist[next.index] = dist[cur.index]+next.cost;
                pq.push({next.index, dist[cur.index]+next.cost});
            }
        }
    }

    cout << dist[B];
    return 0;
}