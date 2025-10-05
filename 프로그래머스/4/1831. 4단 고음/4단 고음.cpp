// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
#include<iostream>

using namespace std;

int cnt;
int N;
int high;
int maxCnt;

// *++++**++ <- 안되는 모양이라서 뒤에서 m, p를 빼면서 진행하면 이 모양 못 잡음

void dfs(int cur, int m, int p) {
    // cout << cur << ' ' << m << ' ' << p << '\n';
    if(cur < 3) return;
    if(m > high) return;
    if(p > high*2) return;
    if(m*2 > p) return; // *++++**++
    
    if(cur == 3 && (m+1)*2 == p) {
        cnt++;
        return;
    }
    
    if(cur%3 == 0) {
        dfs(cur/3, m+1, p);
    }
    dfs(cur-1, m, p+1);    
}

int solution(int n) {
    N = n;
    int answer = 0;
    cnt = 0;
    // +의 개수 = *의 개수의 2배
    
    maxCnt = 1;
    long long val = 3;
    while(val <= N) {
        val*=3;
        maxCnt++;
    }
    high = maxCnt - 1;
    // cnt = high;
    dfs(N, 0, 0);
    
    return cnt;
}