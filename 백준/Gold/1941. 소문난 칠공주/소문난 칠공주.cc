#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>
using namespace std;

char b[8][8];
int ans;
bool used[8][8];
vector<pii> vec;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool check() {
    // for(pii p: vec) {
        // cout << p.first << ' ' << p.second << '\n';
    // }
    // 이어져있는지
    // S가 4개 넘는지
    queue<pii> q;
    q.push({vec[0]});
    bool visited[6][6] = {false, };
    visited[vec[0].first][vec[0].second] = true;


    int cnt = 0;
    int total = 0;
    while(!q.empty()) {
        pii cur = q.front();
        q.pop();
        total++;
        if(b[cur.first][cur.second] == 'S') cnt++;

        for(int i=0; i<4; i++) {
            int r = cur.first + dr[i];
            int c = cur.second + dc[i];
            if(r<0 || r>=5 || c<0 || c>=5 || visited[r][c] || !used[r][c]) continue;
            visited[r][c] = true;
            q.push({r, c});
        }
    }

    // cout << "COUNT: " <<  cnt << '\n';

    return total == 7 && cnt >= 4;
}

void comb(int cur, int depth) {
    if(depth == 7) {
        if (check()) ans++;
        return;
    }

    for(int i=cur; i<25; i++) {
        int r = i/5;
        int c = i%5;
        used[r][c] = true;
        vec.push_back({r, c});
        comb(i+1, depth+1);
        vec.pop_back();
        used[r][c] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin >> b[i][j];
        }
    }

    comb(0, 0);

    cout << ans;
      
    return 0;
}