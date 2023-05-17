#include <iostream>
#include <vector>
#define MAX 2147483647
using namespace std;

vector<pair<int, int>> mat(505);
int dp[505][505];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    for(int i=1; i<=N; i++) {
        int r, c;
        cin >> r >> c;
        mat[i] = {r, c};
    }
    // i=고려하는 행렬 개수, j=시작 행렬 번호, k= j~j+i 사이에서 가능한 모든 행렬 곱 
    for(int i=1; i<=N-1; i++) {
        for(int j=1; j<=N-i; j++) {
            dp[j][j+i] = MAX;
            for(int k=j; k<=j+i-1; k++) {
                // brute force스럽게 곱 개수가 가장 작은거 찾기
                dp[j][j+i] = min(dp[j][j+i], dp[j][k]+dp[k+1][j+i]+mat[j].first*mat[k].second*mat[j+i].second);
            }
        }
    }
    
    cout << dp[1][N];
    return 0;
}