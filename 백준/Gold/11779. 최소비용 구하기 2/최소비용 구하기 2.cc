// 첫째 줄에 도시의 개수 n(1≤n≤1,000)이 주어지고 둘째 줄에는 버스의 개수 m(1≤m≤100,000)이 주어진다. 그리고 셋째 줄부터 m+2줄까지 다음과 같은 버스의 정보가 주어진다. 
// 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 그리고 그 다음에는 도착지의 도시 번호가 주어지고 또 그 버스 비용이 주어진다. 버스 비용은 0보다 크거나 같고, 100,000보다 작은 정수이다.
// 그리고 m+3째 줄에는 우리가 구하고자 하는 구간 출발점의 도시번호와 도착점의 도시번호가 주어진다

// 첫째 줄에 출발 도시에서 도착 도시까지 가는데 드는 최소 비용을 출력한다.
// 둘째 줄에는 그러한 최소 비용을 갖는 경로에 포함되어있는 도시의 개수를 출력한다. 출발 도시와 도착 도시도 포함한다.
// 셋째 줄에는 최소 비용을 갖는 경로를 방문하는 도시 순서대로 출력한다. 경로가 여러가지인 경우 아무거나 하나 출력한다.

#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define INF 2111111111
#define pii pair<int, int>
using namespace std;

struct Node {
    int idx;
    int cost;
    int prev;

    bool operator< (const Node& other) const {
        return cost > other.cost;
    }
};

int N, M;
vector<vector<Node>> g(1005);
pii dist[1005]; // distance, previous node index

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        g[s].push_back({e, c, -1});
    }


    fill_n(&dist[0], 1005, make_pair(INF, 0));
    int S, E;
    cin >> S >> E;
    priority_queue<Node> pq; // idx, cost
    dist[S] = {0, -1};
    for(Node n: g[S]) {
        pq.push({n.idx, n.cost, S});
    }

    while(!pq.empty()) {
        auto [cur, cost, prev] = pq.top();
        pq.pop();

        if(cost < dist[cur].first) {
            dist[cur] = {cost, prev};
            for(Node n: g[cur]) {
                pq.push({n.idx, dist[cur].first+n.cost, cur});
            }
        }
    }

    int prev = dist[E].second;
    stack<int> route;
    route.push(E);
    route.push(prev);

    while(dist[prev].second != -1) {
        prev = dist[prev].second;
        route.push(prev);
    }

    cout << dist[E].first << '\n' << route.size() << '\n';
    while(!route.empty()) {
        cout << route.top() << ' ';
        route.pop();
    }



    return 0;
}