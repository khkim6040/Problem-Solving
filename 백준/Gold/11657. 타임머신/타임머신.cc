#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int N, M;

struct Edge{
    int s, e, c;
};

vector<Edge> edges;

ll dist[555];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int i=0; i<M; i++) {
        int S, E, C;
        cin >> S >> E >> C;
        edges.push_back({S, E, C});
    }

    int INF = 2111111111;
    fill_n(&dist[0], 555, INF);
    dist[1] = 0;

    int cnt = 0;
    bool flag = false;
    while(cnt<N) {
        cnt++;
        for(Edge edge: edges) {
            if(dist[edge.s] == INF) continue;
            if(dist[edge.e] <= dist[edge.s] + edge.c) continue;
            if(cnt == N) {
                flag = true;
                break;
            }
            dist[edge.e] = dist[edge.s] + edge.c;
        }
    }

    bool visit_flag = false;
    for(int i=2; i<=N; i++) {
        if(dist[i] != INF) visit_flag = true;
    }

    if(flag) {
        cout << -1;
    } else {
        for(int i=2; i<=N; i++) {
            dist[i] = dist[i] == INF ? -1 : dist[i];
            cout << dist[i] << '\n';
        }
    }
    
    return 0;
}