#include <iostream>
#include <queue>

using namespace std;

int N, K;
int cnt[100005];
int dist[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    queue<int> q;
    q.push(N);
    cnt[N] = 1;
    int INF = 2111111111;
    fill_n(&dist[0], 100005, INF);
    dist[N] = 0;

    int time = 0;
    while(cnt[K]==0) {
        int size = q.size();
        for(int i=0; i<size; i++) {
            int cur = q.front();
            q.pop();
            
            int nexts[] = {cur+1, cur-1, cur*2};
            for(int next: nexts) {
                if(next<0 || next>100000) continue;
                if(dist[next] == INF) {
                    dist[next] = dist[cur]+1;
                    cnt[next] = cnt[cur];
                    q.push(next);
                } else if(dist[next] == dist[cur]+1) {
                    cnt[next] += cnt[cur];
                }
            }
        }
    }

    cout << dist[K] << '\n' << cnt[K]; 

    return 0;
}