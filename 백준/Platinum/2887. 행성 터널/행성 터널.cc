#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Planet{
    int index;
    int coord;
    bool operator< (const Planet &other) const {
        return coord < other.coord;
    }
};

struct Edge{
    int node1;
    int node2;
    int length;
    bool operator< (const Edge &other) const {
        return length < other.length;
    }
};

int N;
vector<Planet> planets[3];
vector<Edge> edges;
int root[100005];

int getRoot(int node) {
    if(root[node] != node) {
        root[node] = getRoot(root[node]);
    }
    return root[node];
}

void unionParent(int a, int b) {
    int a_root = getRoot(a);
    int b_root = getRoot(b);
    if(a_root < b_root) {
        root[b_root] = a_root;
    }
    else {
        root[a_root] = b_root;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // Edge 구성을 위한 input 처리
    cin >> N;
    for(int i=0; i<N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        planets[0].push_back({i, x});
        planets[1].push_back({i, y});
        planets[2].push_back({i, z});
    }
    sort(planets[0].begin(), planets[0].end());
    sort(planets[1].begin(), planets[1].end());
    sort(planets[2].begin(), planets[2].end());
    
    // Edge 구성
    for(int i=0; i<3; i++) {
        for(int j=0; j<N-1; j++) {
            int node1 = planets[i][j].index;
            int node2 = planets[i][j+1].index;
            int length = planets[i][j+1].coord - planets[i][j].coord;
            edges.push_back({node1, node2, length});
        }
    }
    
    // MST 
    long long answer = 0; // length of MST
    sort(edges.begin(), edges.end());
    for(int i=0; i<N; i++) {
        root[i] = i;
    }
    
    for(auto edge: edges) {
        if(getRoot(edge.node1) != getRoot(edge.node2)) {
            answer += edge.length;
            unionParent(edge.node1, edge.node2);
        }
    }
    
    cout << answer;
    return 0;
}