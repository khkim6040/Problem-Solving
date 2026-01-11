#include <iostream>
#include <unordered_set>

using namespace std;

int N, K;
int cnt[100005];
int dist[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    unordered_set<int> s;
    s.insert(N);
    cnt[N] = 1;
    fill_n(&dist[0], 100005, 2111111111);
    dist[N] = 0;

    int time = 0;
    while(cnt[K] == 0) {
        unordered_set<int> tmp;
        // cout << "TIME: " << time << '\n';
        for(int cur: s) {
            // cout << cur << ' ' << cnt[cur] << '\n';
            if(cur+1 <= 100000 && time <= dist[cur+1]) {
                cnt[cur+1] += cnt[cur];
                dist[cur+1] = time;
                tmp.insert(cur+1);
            }

            if(cur-1 >= 0 && time <= dist[cur-1]) {
                cnt[cur-1] += cnt[cur];
                dist[cur-1] = time;
                tmp.insert(cur-1);
            }

            if(cur*2 <= 100000 && time <= dist[cur*2]) {
                cnt[cur*2] += cnt[cur];
                dist[cur*2] = time;
                tmp.insert(cur*2);
            }
        }

        s = tmp;
        time++;
    }

    // for(int i=0; i<=100000; i++) {
    //     if(!cnt[i]) continue;
    //     cout << i << ' ' << cnt[i] << '\n';
    // }

    cout << time << '\n' << cnt[K]; 

    return 0;
}