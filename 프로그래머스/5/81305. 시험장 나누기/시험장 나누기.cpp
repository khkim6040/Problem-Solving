#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

#define pii pair<int, int>

using namespace std;

int N;
int root;
int isRoot[10005];
vector<int> num;
vector<vector<int>> links;
int K;

int dfs(int cur, const int limit, int& cnt) {
    int sum = num[cur];
    
    int c1 = links[cur][0];
    int sum1 = c1 != -1 ? dfs(c1, limit, cnt) : 0;
    
    int c2 = links[cur][1];
    int sum2 = c2 != -1 ? dfs(c2, limit, cnt) : 0;
    
    // cout << cur << ' '  << limit << ' ' << sum1 << ' ' << sum2 << '\n';
    
    if(sum + sum1 > limit && sum + sum2 > limit) {
        cnt += 2;
    } else if(sum + sum1 > limit) {
        sum += sum2;
        cnt++;
    } else if(sum + sum2 > limit) {
        sum += sum1;
        cnt++;
    } else if(sum + sum1 + sum2 > limit) {
        sum += min(sum1, sum2);
        cnt++;
    } else {
        sum += (sum1 + sum2);
    }
    
    return sum;
}

bool check(int limit, int k) {
    int cnt = 0;
    dfs(root, limit, cnt);
    
    // cout << limit << ' ' << k << ' ' << cnt << '\n';
    return cnt+1 <= k;
}

int solution(int k, vector<int> num_, vector<vector<int>> links_) {
    int answer = 0;
    num = num_;
    links = links_;
    
    // 1~sum(num) 사이에서 가능한 최저 합계(=sum) bisearch O(log(10000*10000))
    
    // root에서부터 leaf 까지 내려갔다가 올라오면서 partial sum > sum이면 cnt++, cnt+1 <= k 로 가능한지 확인 O(V+E)
    
    
    int l = 0;
    int r = 0;
    N = num.size();
    for(int i=0; i<N; i++) {
        isRoot[i] = true;
    }
    for(int i=0; i<N; i++) {
        r += num[i];
        l = max(l, num[i]);
        
        vector<int> link = links[i];
        for(int e: link) {
            if(e==-1) continue;
            isRoot[e] = false;
        }
    }
    
    for(int i=0; i<N; i++) {
        if(isRoot[i]) {
            root = i;
            break;
        }
    }
    
    while(l<r) {
        int mid = (l+r)/2;
        cout << mid << '\n';
        
        if(check(mid, k)) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    
    return r;
}