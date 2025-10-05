#include <string>
#include <vector>

#define INF 2111111111
using namespace std;

// 트리에서의 DP?
// leaf에서 올라오면서 두 가지 상황을 고려
    // 1. 팀장을 선택했을 때
    // 2. 팀장을 선택하지 않았을 때
// 1에서는 팀장이 팀원으로 속한 팀도 조건 만족 -> 1의 경우만 고려, 2의 경우는 이전과 값 같음
// 2에서는 팀장이 팀원으로 속한 팀에서 또 하나를 뽑아야 함 -> 첫 번째 상황과 같이 1, 2또 선택

// dp[N+1][2]
// dp[i][0] => i번 팀장이 있는 팀에서 보낼 사람으로 팀원을 선택할 때 매출액의 최솟값
// dp[i][1] => i번 팀장이 있는 팀에서 보낼 사람으로 팀장 선택할 때 매출액의 최솟값

int dp[300005][2];
int N;

vector<vector<int>> g;
vector<int> sales;

void dfs(int cur) {
    if(g[cur].size() == 0) {
        dp[cur][0] = 0;
        dp[cur][1] = sales[cur-1];
        return;
    }
    
    int minSum = 0; // sum(min(dp[child][0], dp[child][1]))
    for(int child: g[cur]) {
        dfs(child);
        minSum += min(dp[child][0], dp[child][1]);
    }
        

    for(int child: g[cur]) {
        // child를 해당 팀에서 선택했을 때(=다른 child들은 어떤 것이 나와도 ㄱㅊ)
        dp[cur][0] = min(dp[cur][0], minSum - min(dp[child][0], dp[child][1]) + dp[child][1]);
        dp[cur][1] = min(dp[cur][1], minSum + sales[cur-1]);
    }
        
    return;
}

int solution(vector<int> sales_, vector<vector<int>> links) {
    int answer = 0;
    sales = sales_;
    N = sales.size();
    
    g.assign(N+1, vector<int>());
    for(vector<int> link: links) {
        g[link[0]].push_back(link[1]);
    }
    
    for(int i=1; i<=N; i++) {
        dp[i][0] = INF;
        dp[i][1] = INF;
    }
    
    dfs(1);
    
    return min(dp[1][0], dp[1][1]);
}