#include <string>
#include <vector>
#include <iostream>

#define ll long long
using namespace std;

vector<int> diffs;
vector<int> times;
ll limit;
int N;

bool check(int level) {
    ll t = 0;
    for(int i=0; i<N; i++) {
        int diff = diffs[i];
        int time = times[i];
        int trials = max(0, diff-level);
        if(trials) t += 1LL*(time+times[i-1])*trials;
        t += time;
        // cout << t << ' ';
        if(t > limit) return false;
    }
    return true;
}

int solution(vector<int> diffs_, vector<int> times_, long long limit_) {
    diffs = diffs_;
    times = times_;
    limit = limit_;
    N = diffs.size();
    
    int r = -1;
    int l = 1;
    
    for(int diff: diffs) {
        r = max(r, diff);
    }
    
    while(l<=r) {
        int mid = (l+r)/2;
        
        // cout << mid << '\n';
        
        if(check(mid)) {
            // cout << "T" << '\n';
            r = mid-1;
        } else {
            // cout << "F" << '\n';
            l = mid+1;
        }
    }
    
    return l;
}