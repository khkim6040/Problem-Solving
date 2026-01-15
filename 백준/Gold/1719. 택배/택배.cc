#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define INF 2111111111
using namespace std;

struct cmp {
    bool operator() (const pii &a, const pii &b) const{
        return a.second > b.second;
    } 
};

vector<vector<pii>> g;

int N, M;
int dist[222][222];
int prev_[222][222];

void dijk(int start) {
    priority_queue<pii, vector<pii>, cmp> q;

    q.push({start, 0});
    dist[start][start] = 0;
    prev_[start][start] = -1;

    while(!q.empty()) {
        pii cur = q.top();
        q.pop();
        for(pii next: g[cur.first]) {
            if(dist[start][next.first] <= dist[start][cur.first] + next.second) continue;
            dist[start][next.first] = dist[start][cur.first] + next.second;
            prev_[start][next.first] = cur.first;
            q.push({next.first, dist[start][next.first]});
        }
    }
}

int find_first_route(int start, int end) {
    if(prev_[start][end] == start) return end;

    int cur = prev_[start][end];
    while(prev_[start][cur] != start) {
        cur = prev_[start][cur];
    }

    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    g.assign(N+1, vector<pii>());

    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }



    fill_n(&dist[0][0], 222*222, INF);
    for(int i=1; i<=N; i++) {
        dijk(i);
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(i==j) {
                cout << "- ";
            } else {
                cout << find_first_route(i, j) << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}

