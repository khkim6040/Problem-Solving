#include <string>
#include <vector>
#include <iostream>

#define CNT 5
using namespace std;

// 30*29*28*27*26 = 17,100,720 
// 매 조합마다 조건에 맞는지 확인 = 10

vector<vector<bool>> contain;
vector<int> count;
vector<int> condition;

vector<int> cand;

int answer;
int N, M;

bool check() {
    // for(int i=0; i<CNT; i++) {
    //     cout << cand[i] << ' ';
    // }
    // cout << '\n';
    for(int i=0; i<M; i++) {
        int cnt = 0;
        vector<bool> c = contain[i];
        for(int j=0; j<CNT; j++) {
            int num = cand[j];
            if(c[num]) cnt++;
        }
        if(cnt != condition[i]) return false;
    }
    return true;
}

void permu(int cur, int cnt) {
    if(cnt == CNT) {
        if(check()) answer++;
        return;
    }
    
    for(int i=cur; i<=N; i++) {
        cand.push_back(i);
        permu(i+1, cnt+1);
        cand.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    
    N = n;
    M = q.size();
    
    contain.assign(M, vector<bool>(N+1, false));
    condition.assign(M, 0);
    
    for(int i=0; i<M; i++) {
        vector<int> qq = q[i];
        int cond = ans[i];
        for(int e: qq) {
            contain[i][e] = true;
        }
        condition[i] = cond;
    }
    
    // for(auto cont: contain) {
    //     for(int i=0; i<N+1; i++) {
    //         cout << cont[i] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    permu(1, 0);
    return answer;
}