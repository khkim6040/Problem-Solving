#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define pii pair<int, int>

using namespace std;

int N, M, D;
vector<int> v;
int ans;
int b[22][22];
bool visited[22][22];

int dr[] = {0, -1, 0};
int dc[] = {-1, 0, 1};

pii find_monster(int pr, int pc) {
    bool vis[22][22] = {false, };
    queue<pii> q;
    if(b[pr-1][pc] && !visited[pr-1][pc]) return {pr-1, pc};
    q.push({pr-1, pc});
    vis[pr-1][pc] = true;

    int cnt = 2;
    while(!q.empty() && cnt<=D) {
        int size = q.size();
        cnt++;
        for(int i=0; i<size; i++) {
            pii cur = q.front();
            q.pop();

            for(int j=0; j<3; j++) {
                int r = cur.first + dr[j];
                int c = cur.second + dc[j];
                if(r<0 || r>=N || c<0 || c>=M || vis[r][c]) continue;
                if(b[r][c] && !visited[r][c]) return {r, c};
                vis[r][c] = true;
                q.push({r, c});
            }
        }
    }

    return {-1, -1};
}

// 가능한 궁수 자리 조합 * (궁수 인원 * (고려할 행 길이 * (사거리 * 가로길이)))
// 2000 * (15 * (15 * (10 * 15))) = 30,000,000
int simulate() {
    int ret = 0;
    fill_n(&visited[0][0], 22*22, false);
    for(int r=N; r>0; r--) {
        vector<pii> vis_v;
        for(int c: v) {
            pii monster = find_monster(r, c);
            if(monster.first == -1) continue;
            vis_v.push_back(monster);
        }
        // 같은 몬스터가 여러 궁수에게 공격받을 수 있으므로 턴이 끝난 후 vistied 처리
        for(pii p: vis_v) {
            if(visited[p.first][p.second]) continue;
            visited[p.first][p.second] = true;
            ret++;
        }
    }


    return ret;
}

void comb(int cnt, int idx) {
    if(cnt == 3) {
        ans = max(ans, simulate());
        return;
    }

    for(int i=idx; i<M; i++) {
        v.push_back(i);
        comb(cnt+1, i+1);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> D;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> b[i][j];
        }
    }

    comb(0, 0);

    cout << ans;
    return 0;
}