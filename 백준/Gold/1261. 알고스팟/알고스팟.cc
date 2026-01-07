#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define pii pair<int, int>
using namespace std;

struct Node {
    int r, c, cnt;
};

int N, M;
int b[105][105];
bool visited[105][105][10005];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool check(int limit) {
    queue<Node> q;
    q.push({1, 1, 0});

    fill_n(&visited[0][0][0], 105*105*10005, false);
    visited[1][1][0] = true;

    while(!q.empty()) {
        Node cur = q.front();
        q.pop();

        if(cur.r == N && cur.c == M) {
            return true;
        }

        for(int i=0; i<4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];
            if(r<=0 || r>N || c<=0 || c>M) continue;
            if(b[r][c] == 1) {
                if(cur.cnt == limit) continue;
                if(visited[r][c][cur.cnt+1]) continue;
                visited[r][c][cur.cnt+1] = true;
                q.push({r, c, cur.cnt+1});
            } else {
                if(visited[r][c][cur.cnt]) continue;
                visited[r][c][cur.cnt] = true;
                q.push({r, c, cur.cnt});
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;

    int cnt = 0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            char c;
            cin >> c;
            b[i][j] = c-'0';
            if(b[i][j]==1) cnt++;
        }
    }

    int l = 0;
    int r = cnt;

    while(l<=r) {
        int mid = (l+r)/2;
        // cout << l << ' ' << r << '\n';
        if(check(mid)) {
            // cout << "T\n";
            r = mid-1;
        } else {
            // cout << "F\n";
            l = mid+1;
        }
    }

    cout << r+1;

    return 0;
}