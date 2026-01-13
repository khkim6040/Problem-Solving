#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int N, K;
int dist[100005];
int prev_[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    int INF = 2111111111;
    fill_n(&dist[0], 100005, INF);
    dist[N] = 0;
    prev_[N] = -1;

    queue<int> q;
    q.push(N);

    while(!q.empty() && dist[K] == INF) {
        int cur = q.front();
        q.pop();

        int nexts[] = {cur-1, cur+1, cur*2};
        for(int next: nexts) {
            if(next<0 || next>100000 || dist[next] != INF) continue;
            dist[next] = dist[cur]+1;
            prev_[next] = cur;
            q.push(next);
        }
    }

    cout << dist[K] << '\n';
    int cur = K;
    stack<int> s;
    while(cur != -1) {
        s.push(cur);
        cur = prev_[cur];
    }

    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    
    
    return 0;
}

