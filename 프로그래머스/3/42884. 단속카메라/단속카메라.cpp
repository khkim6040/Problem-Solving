#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct Node{
    int spot;
    int isOut;
    int idx;
};

bool cmp (const Node& a, const Node& b) {
    if (a.spot == b.spot) return a.isOut < b.isOut; // 시작 == 끝 일 때 시작을 먼저 넣음
    return a.spot < b.spot;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    int size = routes.size();
    vector<Node> vec;
    for(int i=0; i<size; i++) {
        vector<int> r = routes[i];
        vec.push_back({r[0], 0, i});
        vec.push_back({r[1], 1, i});
    }
    sort(vec.begin(), vec.end(), cmp);
    // 배열 for
    int spot = -33333;
    int cnt = 0;
    for(int i=0; i<2*size; i++) {
        Node cur = vec[i];
        if(cur.isOut) {
            int curStart = routes[cur.idx][0];
            if(curStart > spot) {
                cnt++;
                spot = cur.spot;
            }
        }
    }
        // 끝일 때 
        // 시작이 현재 카메라 위치보다 뒤라면 개수++, 카메라 위치 = 끝
        // 시작이 현재 카메라 위치보다 같거나 작다면 그냥 뺌
    
//     for(Node n: vec) {
//         cout << n.spot << ' ' << n.isOut << ' ' << n.idx << '\n';
//     }
    
    
    return cnt;
}