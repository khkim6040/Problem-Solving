#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> answer;

vector<vector<int>> g; // child는 오름차순으로 정렬됨
int curPointer[105]; // 각 부모 노드가 몇 번째의 child를 가리키는지
int N;
int cnt[105];
bool isPossible[105];
vector<int> leaves;
vector<int> sequences;

int getNext(int cur) {
    if(g[cur].size() == 0) {
        return cur;
    }
    
    int pointer = curPointer[cur];
    curPointer[cur] = (curPointer[cur]+1)%g[cur].size();
    return getNext(g[cur][pointer]);
}

bool checkPossible() {
    for(int i=1; i<=N; i++) {
        if (isPossible[i] == false) {
            return false;
        }
    }
    return true;
}

// 가장 적은 횟수
// 사전순

// next 뽑기. 차례마다 떨어질 leaf node는 정해져있음
// while true
    // int next = getNext()
    // if cnt[next] >= target[next] -> 불가능, break;
    // cnt[next]++
    // if 3*cnt[next] >= target[next] possible[next] = true

    // if checkPossible() break;

// 채우기
// target = 5, cnt = 3 이라면 1 1 3 으로 채워야 함. 어떻게?
// 6, 3 일 때는 1 2 3
// for ele: sequences
    // 1 가능성 확인
    // if 3*(cnt[leaf]-1) >= target[leaf]-1 => 가능
    // 2 가능성 확인
    // else if 3*(cnt[leaf]-1) >= target[leaf]-2 => 가능
    // 3 가능성 확인
    // else if 3*(cnt[leaf]-1) >= target[leaf]-3 => 가능
    // else (error)
    
    // answer.push_back(val)
    // cnt[leaf]--;
    // target[leaf] -= val;




vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    N = target.size();
    g.resize(N+1);
    for(vector<int> edge: edges) {
        g[edge[0]].push_back(edge[1]);
    }
    
    for(int i=1; i<=N; i++) {
        if(target[i-1] == 0) isPossible[i] = true;
        sort(g[i].begin(), g[i].end());
    }

    
    while(true) {
        int next = getNext(1);
        // cout << next << ' ';
        if (cnt[next] == target[next-1]) {
            answer.push_back(-1);
            return answer;
        } 
        cnt[next]++;
        sequences.push_back(next);
        if (3*cnt[next] >= target[next-1]) {
            isPossible[next] = true;
        }

        if (checkPossible()) break;
    }
    
    for(int leaf: sequences) {
        int val = 3;
        if (3*(cnt[leaf]-1) >= target[leaf-1]-1) {
            val = 1;
        } else if(3*(cnt[leaf]-1) >= target[leaf-1]-2) {
            val = 2;
        } else if(3*(cnt[leaf]-1) >= target[leaf-1]-3) {
            val = 3;
        } else {
            exit(1);
        }

        answer.push_back(val);
        cnt[leaf]--;
        target[leaf-1] -= val;
    }
    
    
    
    
    return answer;
}




