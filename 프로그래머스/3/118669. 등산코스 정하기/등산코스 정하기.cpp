#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

#define NONE 0
#define GATE 1
#define SUMMIT 2

#define pii pair<int, int>

using namespace std;

int parent[50005];
pii type[50005];
bool isGate[50005];
bool isSummit[50005];

struct Edge {
    int a;
    int b;
    int cost;
    
    void print_() {
        cout << cost << ' ' << a << ' ' << b << '\n';
    }
};

bool cmp(const Edge& a, const Edge& b) {
    if(a.cost == b.cost) {
        int sa = isSummit[a.a] ? a.a : isSummit[a.b] ? a.b : -1;
        int sb = isSummit[b.a] ? b.a : isSummit[b.b] ? b.b : -1;
        if(sa != -1 && sb != -1) {
            return sa < sb;
        }
    }
    return a.cost < b.cost;
}

int find(int a) {
    if(a == parent[a]) return a;
    
    return parent[a] = find(parent[a]);
}

void merge(int a, int b, int t, int src) {
    int pa = find(a);
    int pb = find(b);
    
    if(pa==pb) return;
    if(pa>pb) swap(pa, pb);
    
    parent[pb] = pa;
    type[pa] = {t, src};
}

pii getType(int a) {
    int pa = find(a);
    
    return type[pa];
}

vector<int> solution(int N, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<vector<int>> answer;
    
    // 다익스트라 paths * gates 번 = O(ElogV * N^2) 시간초과
    
    // MST 만들기
    // 작은 간선부터 계속 잇다가 path, gate 이어지는 순간에 컷
    // paths끼리, gates끼리 안 이어지게끔 조건 설정
    // 간선 하나에 path, gate 연결, path 두 개, 혹은 gate 두 개 고려
    for(int g: gates) {
        isGate[g] = true;
    }
    for(int s: summits) {
        isSummit[s] = true;
    }
    for(int i=1; i<=N; i++) {
        parent[i] = i;
        if(isGate[i]) {
            type[i] = {GATE, i};
        } else if(isSummit[i]) {
            type[i] = {SUMMIT, i};
        } else {
            type[i] = {NONE, i};
        }
    }
    
    vector<Edge> edges;
    for(auto path: paths) {
        edges.push_back({path[0], path[1], path[2]});
    }
    sort(edges.begin(), edges.end(), cmp);
    
    for(Edge e: edges) {
        int a = find(e.a);
        int b = find(e.b);
        if(a == b) continue;
        pii pa = getType(a);
        pii pb = getType(b);
        int ta = pa.first;
        int tb = pb.first;
        if(ta == GATE && tb == GATE) continue;
        if(ta == SUMMIT && tb == SUMMIT) continue;
        
        if(ta == GATE && tb == SUMMIT) {
            vector<int> temp;
            temp.push_back(pb.second);
            temp.push_back(e.cost);
            answer.push_back(temp);
            continue;
        } else if(ta == SUMMIT && tb == GATE) {
            vector<int> temp;
            temp.push_back(pa.second);
            temp.push_back(e.cost);
            answer.push_back(temp);
            continue;
        }
        
        int t = max(ta, tb);
        int src = ta >= tb ? pa.second : pb.second;
        merge(a, b, t, src);
    }
    
    int cost = 2111111111;
    int idx = -1;
    for(vector<int> v: answer) {
        if(v[1] == cost) {
            if(v[0] < idx) {
                idx = v[0];
            }
        } else if(v[1] < cost) {
            cost = v[1];
            idx = v[0];
        }
    }
    
    vector<int> a;
    a.push_back(idx);
    a.push_back(cost);
    return a;
}