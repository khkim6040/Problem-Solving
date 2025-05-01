#include <iostream>
#include <vector>

#define pii pair<int, int>
using namespace std;

pii t[4000005]; // {맛, 개수}

void update(int node, int s, int e, int idx, int diff) {
    if(s==e) {
        t[node] = {idx, t[node].second+diff}; 
        return;
    }

    int mid = (s+e)/2;
    if(idx<=mid) {
        update(node*2, s, mid, idx, diff);
    } else {
        update(node*2+1, mid+1, e, idx, diff);
    }

    t[node] = {0, t[node*2].second + t[node*2+1].second};
}

int find(int node, int s, int e, int rank) {
    if(t[node].first && t[node].second >= rank) {
        return t[node].first;
    }

    int mid = (s+e)/2;
    if(t[node*2].second >= rank) {
        return find(node*2, s, mid, rank);
    } else {
        return find(node*2+1, mid+1, e, rank-t[node*2].second);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin >> N;
    while(N--) {
        int cmd;
        cin >> cmd;
        if(cmd==1) {
            int rank;
            cin >> rank;
            int tasty = find(1, 1, 1000000, rank);
            cout << tasty << '\n';
            update(1, 1, 1000000, tasty, -1); // 하나 빼야함
        } else {
            int tasty, diff;
            cin >> tasty >> diff;
            update(1, 1, 1000000, tasty, diff);
        }
    }
    return 0;
}