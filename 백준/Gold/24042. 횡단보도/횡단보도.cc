#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define pll pair<ll, ll>
#define INF 777777777777
using namespace std;

int N, M;
vector<vector<pll>> g;

struct cmp{
    bool operator() (const pll &a, const pll &b) {
        return a.second > b.second;
    }
};

ll dist[100005];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    /* 0초에서 1에서 시작. 근처로 갈 수 있는 곳 연결
    / 연결된 곳 각각에서 다른 곳으로 뻗어나가는것 신호 주기 고려해서 계산
        / ex) 2번에 1초에 도착 (이게 최단거리임)
        / 2번에서 3, 4, 5, 6을 7, 6, 5, 4 번째에 각각 갈 수 있다고 해보자. M = 7
        / 주기마다 번호별로 2 -> i 도착시각
        / 3: 7(만약 6초 이하에서 출발한다면), 14(7초~13초), 21
        / 4: 6, 13, 20
        / 5: 5, 12
        / 6: 4, 11
        / i -> j 로 가는 시각 계산: div = dist[i]/M * M, dist[i]%M >= seq[j] 라면, dist[j] = div + M + seq[j], else dist[j] = div + seq[j] 
    */

    g.assign(N+1, vector<pll>());
    for(ll i=1; i<=M; i++) {
        ll s, e;
        cin >> s >> e;
        g[s].push_back({e, i});
        g[e].push_back({s, i});
    }

    priority_queue<pll, vector<pll>, cmp> q;
    q.push({1, 0});
    fill_n(&dist[0], N+1, INF);
    dist[1] = 0;

    while(!q.empty()) {
        pll cur = q.top();
        ll idx = cur.first;
        q.pop();
        for(pll next: g[idx]) {
            ll div = dist[idx]/M * M;
            ll cost = div + next.second;
            if(dist[idx]%M >= next.second) cost += M;

            if(cost >= dist[next.first]) continue;
            dist[next.first] = cost;
            q.push({next.first, cost});
        }
    }


    cout << dist[N];

    return 0;
}