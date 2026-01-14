#include <iostream>
#include <queue>

#define INF 2111111111
using namespace std;

int N;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

struct Node {
    int r, c, cost;

    bool operator< (const Node &other) const {
        return cost > other.cost;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0;
    while(true) {
        cin >> N;
        if(N==0) break;

        cnt++;
        int b[155][155];
        int dist[155][155];
        fill_n(&dist[0][0], 155*155, INF);
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cin >> b[i][j];
            }
        }

        priority_queue<Node> q;
        q.push({0, 0, b[0][0]});

        while(!q.empty()) {
            Node cur = q.top();
            q.pop();

            if(cur.r == N-1 && cur.c == N-1) break;

            for(int i=0; i<4; i++) {
                int r = cur.r + dr[i];
                int c = cur.c + dc[i];
                // cur.cost == dist[cur.r][cur.c]
                if(r<0 || r>=N || c<0 || c>=N || dist[r][c] <= cur.cost + b[r][c]) continue;
                dist[r][c] = cur.cost + b[r][c];
                q.push({r, c, dist[r][c]});
            }
        }

        cout << "Problem " << cnt << ": " << dist[N-1][N-1] << '\n'; 
    }

    
    
    return 0;
}

