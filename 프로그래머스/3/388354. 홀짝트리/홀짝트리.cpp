#include <string>
#include <vector>

using namespace std;

vector<vector<int>> g;
bool visited[1000005];
bool isNode[1000005];

int cnt1; // 역홀짝 노드 수. 이웃과 번호의 홀/짝이 다름
int cnt2; // 홀짝 노드 수

void dfs(int cur) {
    
    visited[cur] = true;
    
    bool isOdd = cur%2 == 1; // 홀수
    
    // 이웃 수 홀수
    if(g[cur].size()%2 == 1) {
        if(isOdd) {
            cnt2++;
        } else {
            cnt1++;
        }
    // 이웃 수 짝수
    } else {
        if(isOdd) {
            cnt1++;
        } else {
            cnt2++;
        }
    }
    
    for(int next: g[cur]) {
        if(visited[next]) continue;
        dfs(next);
    }
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer;
    int ans1 = 0;
    int ans2 = 0;
    g.assign(1000005, vector<int>());
    // 그래프 별 노드들 탐색
    // 이웃 개수로 홀짝/역홀짝 노드 판단
        // 이웃 개수, 번호 모두 홀/짝 -> 홀짝노드
        // 그 외 -> 역홀짝노드
    // 역홀짝 1(루트가 됨), 나머지 홀짝노드 -> 역홀짝트리
    // 홀짝 1(루트가 됨), 나머지 역홀짝 -> 홀짝트리
    // 그 외 -> 불가능
    for(int node: nodes) {
        isNode[node] = true;
    }
    for(auto edge: edges) {
        int s = edge[0];
        int e = edge[1];
        g[s].push_back(e);
        g[e].push_back(s);
    }
    
    for(int i=0; i<1000005; i++) {
        if(!isNode[i]) continue;
        if(!visited[i]) {
            cnt1 = 0;
            cnt2 = 0;
            dfs(i);
            if(cnt1 == 1) {
                ans2++;
            }
            if(cnt2 == 1) {
                ans1++;
            }
        }
    }
    
    answer.push_back(ans1);
    answer.push_back(ans2);
    return answer;
}