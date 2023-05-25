#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> graph[1005];
int in_order[1005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int size;
        cin >> size;
        int pre = 0;
        int cur;
        for(int j=0; j<size; j++) {
            cin >> cur;
            graph[pre].push_back(cur);
            in_order[cur]++;
            pre = cur;
        }
    }
    // Topological Order
    vector<int> answer;
    queue<int> q;
    q.push(0);
    for(int i=1; i<=N; i++) {
        if(in_order[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(cur!=0) {
            answer.push_back(cur);
        }
        for(int next: graph[cur]) {
            in_order[next]--;
            if(in_order[next]==0) {
                q.push(next);
            }
        }
    }
    // print
    if(answer.size() < N) {
        cout << 0;
    } 
    else {
        for(int ele: answer) {
            cout << ele << '\n';
        }
    }
    
    return 0;
}