#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;

int targetAlp;
int targetCop;
int maxAlp;
int maxCop;
int curAlp;
int curCop;

int answer = 305;

vector<vector<int>> problems;

int dp[155][155];

void dfs(int alp, int cop, int cost) {
    alp = min(maxAlp, alp);
    cop = min(maxCop, cop);
    if(dp[alp][cop] <= cost) return;
    
    dp[alp][cop] = cost;

    if(alp >= targetAlp && cop >= targetCop) {
        // cout << alp << ' ' << cop << ' ' << cost << '\n';
        answer = min(answer, cost);
        return;
    }
    if(cost >= answer) return;

    
    for(auto p: problems) {
        int alpReq = p[0];
        int copReq = p[1];
        if(alp >= alpReq && cop >= copReq) {
            dfs(alp+p[2], cop+p[3], cost+p[4]);
        }
    }
}

int solution(int alp, int cop, vector<vector<int>> problems_) {
    
    problems = problems_;
    problems.push_back({0, 0, 0, 1, 1});
    problems.push_back({0, 0, 1, 0, 1});
    N = problems.size();
    
    
    for(int i=0; i<N; i++) {
        vector<int> p = problems[i];
        targetAlp = max(targetAlp, p[0]);
        targetCop = max(targetCop, p[1]);
    }
    
    maxAlp = max(targetAlp, alp);
    maxCop = max(targetCop, cop);
    
    for(int i=alp; i<=maxAlp; i++) {
        for(int j=cop; j<=maxCop; j++) {
            dp[i][j] = 2111111111;
        }
    }
    
    dp[alp][cop] = 0;
    for(int i=alp; i<=maxAlp; i++) {
        for(int j=cop; j<=maxCop; j++) {
            dp[min(i+1, maxAlp)][j] = min(dp[min(i+1, maxAlp)][j], dp[i][j] + 1);
            dp[i][min(j+1, maxCop)] = min(dp[i][min(j+1, maxCop)], dp[i][j] + 1);
            
            for(auto p: problems) {
                if(i<p[0]) continue;
                if(j<p[1]) continue;
                
                int a = min(i+p[2], maxAlp);
                int b = min(j+p[3], maxCop);
                dp[a][b] = min(dp[a][b], dp[i][j] + p[4]); 
            }
        }
    }
    
    return dp[maxAlp][maxCop];
}