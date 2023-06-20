#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> graph;
int occupying_index[205];
bool is_assigned[205];

bool dfs(int cur) {
    for(int want: graph[cur]) {
        if(is_assigned[want]) {
            continue;
        }
        is_assigned[want] = true;
        if(occupying_index[want]==0 || dfs(occupying_index[want])) {
            occupying_index[want] = cur;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    graph.assign(N+1, vector<int>());
    for(int i=1; i<=N; i++) {
        int size;
        cin >> size;
        for(int j=0; j<size; j++) {
            int x;
            cin >> x;
            graph[i].push_back(x);
        }
    }

    int count = 0;
    for(int i=1; i<=N; i++) {
        fill(is_assigned, is_assigned+205, false);
        if(dfs(i)) {
            count++;
        }
        
    }

    cout << count;
    return 0;
}

