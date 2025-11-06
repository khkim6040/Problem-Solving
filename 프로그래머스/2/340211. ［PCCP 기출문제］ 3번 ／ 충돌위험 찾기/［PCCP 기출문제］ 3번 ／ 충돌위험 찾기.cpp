#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

#define pii pair<int, int>

using namespace std;


struct Node {
    int idx;
    int targetIdx;
    int r;
    int c;
};

int N, M;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    vector<int> tmp;
    tmp.push_back(0);
    tmp.push_back(0);
    points.insert(points.begin(), tmp);
    int answer = 0;
    
    // 큐에 로봇 별 시작 포지션들 다 넣음
    N = points.size();
    M = routes.size();
    queue<Node> q;
    for(int i=0; i<M; i++) {
        int first = routes[i][0];
        int r = points[first][0];
        int c = points[first][1];
        q.push({i, 0, r, c});
    }
    
    while(!q.empty()) {
        int size = q.size();
        unordered_map<int, int> m; // m[r*100+c] = 해당 포인트에 존재하는 로봇 수
        
        for(int k=0; k<size; k++) {
            Node cur = q.front();
            q.pop();
            int pos = cur.r*100 + cur.c;
            if(m[pos] == 1) answer++;
            if(!m[pos]) {
                m[pos] = 1;
            } else {
                m[pos]++;
            }
            
            // 현재 로봇의 현재 목표로 진행 후 큐에 삽입
            vector<int> route = routes[cur.idx];
            // 도착했는지 확인
            vector<int> point = points[route[cur.targetIdx]];
            int rr = point[0];
            int rc = point[1];
            int cr = cur.r;
            int cc = cur.c;
            if(rr == cr && rc == cc) {
                if(route.size() == cur.targetIdx+1) continue;
                
                int nextTargetIdx = cur.targetIdx + 1;
                vector<int> nextPoint = points[route[nextTargetIdx]];
                rr = nextPoint[0];
                rc = nextPoint[1];
                if(rr == cr) {
                    if(rc > cc) {
                        q.push({cur.idx, nextTargetIdx, cr, cc+1});
                    } else {
                        q.push({cur.idx, nextTargetIdx, cr, cc-1});
                    }
                } else {
                    if(rr > cr) {
                        q.push({cur.idx, nextTargetIdx, cr+1, cc});
                    } else {
                        q.push({cur.idx, nextTargetIdx, cr-1, cc});
                    }
                }
            } else {
                if(rr == cr) {
                    if(rc > cc) {
                        q.push({cur.idx, cur.targetIdx, cr, cc+1});
                    } else {
                        q.push({cur.idx, cur.targetIdx, cr, cc-1});
                    }
                } else {
                    if(rr > cr) {
                        q.push({cur.idx, cur.targetIdx, cr+1, cc});
                    } else {
                        q.push({cur.idx, cur.targetIdx, cr-1, cc});
                    }
                }
            }
        }
    }
    
    return answer;
}