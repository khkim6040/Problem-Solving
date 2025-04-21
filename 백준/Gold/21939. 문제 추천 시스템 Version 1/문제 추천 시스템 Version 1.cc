#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node1 {
    int idx;
    int diff;
    // Min
    const bool operator< (const Node1& other) const {
        if (diff == other.diff) {
            return idx > other.idx;
        }
        return diff > other.diff;
    }
};

struct Node2 {
    int idx;
    int diff;
    // Max
    const bool operator< (const Node2& other) const {
        if (diff == other.diff) {
            return idx < other.idx;
        }
        return diff < other.diff;
    }
};

priority_queue<Node1> minpq;
priority_queue<Node2> maxpq;
int idx_to_diff[1000005];
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++) {
        int idx, diff;
        cin >> idx >> diff;
        idx_to_diff[idx] = diff;
        minpq.push({idx, diff});
        maxpq.push({idx, diff});
    }

    cin >> M;
    while(M--) {
        string cmd;
        cin >> cmd;
        if(cmd == "add") {
            int idx, diff;
            cin >> idx >> diff;
            minpq.push({idx, diff});
            maxpq.push({idx, diff});
            idx_to_diff[idx] = diff;
        } else if (cmd == "recommend") {
            int x;
            cin >> x;
            if(x==1) {
                while(idx_to_diff[maxpq.top().idx] != maxpq.top().diff) {
                    maxpq.pop();
                }
                auto [idx, diff] = maxpq.top();
                cout << idx << '\n';
            } else {
                while(idx_to_diff[minpq.top().idx] != minpq.top().diff) {
                    minpq.pop();
                }
                auto [idx, diff] = minpq.top();
                cout << idx << '\n';
            }
        } else {
            int idx;
            cin >> idx;
            idx_to_diff[idx] = 0;
        }
    }
    


    return 0;
}
 