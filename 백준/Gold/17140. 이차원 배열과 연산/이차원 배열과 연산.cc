#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int b[105][105];
int R, C, K;
int row_cnt=3;
int col_cnt=3;

struct Node {
    int cnt;
    int v;

    bool operator< (const Node& other) const {
        if (cnt == other.cnt) {
            return v > other.v;
        }

        return cnt > other.cnt;
    }
};

void R_() {
    int tmp[105][105] = {0, };

    for(int i=1; i<=row_cnt; i++) {
        map<int, int> m;
        for(int j=1; j<=col_cnt; j++) {
            if(b[i][j]==0) continue;
            
            int v = b[i][j];
            if(m[v]) {
                m[v]++;
            } else {
                m[v] = 1;
            }
        }
        // Arrange by count
        priority_queue<Node> pq;
        for(auto iter: m) {
            int v = iter.first;
            int cnt = iter.second;
            pq.push({cnt, v});
        }
        // Make a row
        vector<int> vec;
        while(!pq.empty()) {
            auto [cnt, v] = pq.top();
            pq.pop();

            vec.push_back(v);
            vec.push_back(cnt);
        }
        int cnt = 1;
        for(int ele: vec) {
            if(cnt > 100) break;
            tmp[i][cnt] = ele;
            cnt++;
        }
        col_cnt = max(col_cnt, cnt-1);
    }
    // Reflect to original array
    copy(&tmp[1][1], &tmp[100][100], &b[1][1]);
}

void C_() {
    int tmp[105][105] = {0, };

    for(int j=1; j<=col_cnt; j++) {
        map<int, int> m;
        for(int i=1; i<=row_cnt; i++) {
            if(b[i][j]==0) continue;
            
            int v = b[i][j];
            if(m[v]) {
                m[v]++;
            } else {
                m[v] = 1;
            }
        }
        // Arrange by count
        priority_queue<Node> pq;
        for(auto iter: m) {
            int v = iter.first;
            int cnt = iter.second;
            pq.push({cnt, v});
        }
        // Make a row
        vector<int> vec;
        while(!pq.empty()) {
            auto [cnt, v] = pq.top();
            pq.pop();

            vec.push_back(v);
            vec.push_back(cnt);
        }
        int cnt = 1;
        for(int ele: vec) {
            if(cnt > 100) break;
            tmp[cnt][j] = ele;
            cnt++;
        }
        row_cnt = max(row_cnt, cnt-1);
    }
    // Reflect to original array
    copy(&tmp[1][1], &tmp[100][100], &b[1][1]);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> K;

    for(int i=1; i<=3; i++) {
        for(int j=1; j<=3; j++) {
            cin >> b[i][j];
        }
    }

    // R_();

    // for(int i=1; i<=3; i++) {
    //     for(int j=1; j<=6; j++) {
    //         cout << b[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    if(b[R][C] == K) {
        cout << 0;
        return 0;
    }

    int t = 0;
    while(t<=100) {
        t++;

        if(row_cnt >= col_cnt) {
            // cout << 'R' << '\n';
            R_();
        } else {
            // cout << 'C' << '\n';
            C_();
        }

        if(b[R][C] == K) {
            break;
        }

        // for(int i=1; i<=row_cnt; i++) {
        //     for(int j=1; j<=col_cnt; j++) {
        //         cout << b[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

    }

    if(t==101) t=-1;

    cout << t;
 
    return 0;
}