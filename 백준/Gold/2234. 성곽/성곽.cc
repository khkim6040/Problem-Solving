#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>
using namespace std;

int N, M;
int b[55][55];
int room_size[2555];
int mark[55][55];
vector<vector<int>> adj_mark; // adj_mark[i]: mark i와 인접한 mark들

bool visited[55][55];

int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};

// ans
int room_cnt;
int largest_room_size;
int largest_shared_room_size;

// room_cnt 리턴, adj_mark 채움
int mark_(int pr, int pc, int mark_cnt) {
    int ret = 1;
    queue<pii> q;
    q.push({pr, pc});
    visited[pr][pc] = true;
    mark[pr][pc] = mark_cnt;

    while(!q.empty()) {
        pii cur = q.front();
        q.pop();
        
        int val = b[cur.first][cur.second];
        for(int i=0; i<4; i++) {
            int r = cur.first + dr[i];
            int c = cur.second + dc[i];
            if(r<0 || r>=N || c<0 || c>=M) continue;

            int mask = 1<<i;
            bool test = mask & val;
            if(test) {
                if(mark[r][c] != 0 && mark[r][c] != mark_cnt) adj_mark[mark_cnt].push_back(mark[r][c]);
                continue;
            }

            if(visited[r][c]) continue;
            ret++;
            visited[r][c] = true;
            mark[r][c] = mark_cnt;
            q.push({r, c});
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;

    adj_mark.assign(N*M+1, vector<int>());

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> b[i][j];
        }
    }

    int mark_cnt = 1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(visited[i][j]) continue;
            room_cnt++;
            room_size[mark_cnt] = mark_(i, j, mark_cnt);
            largest_room_size = max(largest_room_size, room_size[mark_cnt]);
            mark_cnt++;
        }
    }    

    for(int cur=0; cur<adj_mark.size(); cur++) {
        vector<int> v = adj_mark[cur];
        if(v.size() == 0) continue;
        for(int adj: v) {
            largest_shared_room_size = max(largest_shared_room_size, room_size[cur]+room_size[adj]);
        }
    }

    // for(int i=0; i<N; i++) {
    //     for(int j=0; j<M; j++) {
    //         cout << mark[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }  

    cout << room_cnt << '\n' << largest_room_size << '\n' << largest_shared_room_size;


    return 0;
}