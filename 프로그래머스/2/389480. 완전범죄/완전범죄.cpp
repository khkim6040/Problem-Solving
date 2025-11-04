#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;

bool cmp(vector<int> a, vector<int> b) {
    return float(a[0])/a[1] > float(b[0])/b[1]; // 값 범위 1~3이므로 값마다 나오는 수 조합 유일함
}

int solution(vector<vector<int>> info, int n, int m) {
    int prevN = n;
    N = info.size();
    
    sort(info.begin(), info.end(), cmp);
    
    for(int i=0; i<N; i++) {
        // cout << info[i][0] << ' ' << info[i][1] << '\n';
        if(m > info[i][1]) {
            m -= info[i][1];
        } else if(n > info[i][0]) {
            n -= info[i][0];
        } else {
            return -1;
        }
    }
    
    return prevN-n;
}