#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int N, M;
int inorder[1005];
int answer[1005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    vector<vector<int>> graph(N+1);
    for(int i=0; i<M; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        inorder[e]++;
    }

    // Topological Ordering
    queue<int> q;
    for(int i=1; i<=N; i++) {
        if(inorder[i]==0) {
            q.push(i);
        }
    }

    int count = 0;
    while(!q.empty()) {
        int size = q.size();
        count++;
        for(int i=0; i<size; i++) {
            int cur = q.front();
            q.pop();
            answer[cur] = count;
            for(int next: graph[cur]) {
                inorder[next]--;
                if(inorder[next]==0) {
                    q.push(next);
                }
            }
        }
    }

    for(int i=1; i<=N; i++) {
        cout << answer[i] << ' ';
    }
    return 0;
}