#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define pii pair<int, int>
#define INF 211111111

using namespace std;

int V, E, P;

vector<vector<pii>> g; // first = idx, second = cost

struct cmp{
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};


int get_shortest_dist(int start, int end) {
    priority_queue<pii, vector<pii>, cmp> q;
    vector<int> dist;
    dist.assign(V+1, INF);
    dist[start] = 0;
    q.push({start, 0});

    while(!q.empty()) {
        pii qq = q.top();
        q.pop();
        int cur = qq.first;
        int cost = qq.second;

        if(cur == end) break;

        for(pii next: g[cur]) {
            int n_cost = cost + next.second;
            if(n_cost >= dist[next.first]) continue;
            dist[next.first] = n_cost;
            q.push({next.first, n_cost});
        }
    }

    return dist[end];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E >> P;

    g.assign(V+1, vector<pii>());

    for(int i=0; i<E; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        g[s].push_back({e, c});
        g[e].push_back({s, c});
    }

    // A: 민준 -> V 최단거리
    int A = get_shortest_dist(1, V);

    // B: 민준 -> 건우 최단거리 
    int B = get_shortest_dist(1, P);

    // C: 건우 -> V 최단거리
    int C = get_shortest_dist(P, V);

    // cout << A << ' ' << B << ' ' << C <<'\n';
    // A == B + C 이면 가능
    if(A == B+C) {
        cout << "SAVE HIM";
    } else {
        cout << "GOOD BYE";
    }
    
    return 0;
}