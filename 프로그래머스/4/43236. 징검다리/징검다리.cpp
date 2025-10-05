#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int distance_;
vector<int> rocks;
int N;
int size_;

bool check(int dist) {
    int cnt = 0;
    int gap = 0;
    int from = 0;
    for(int i=0; i<=size_; i++) {
        gap = i==size_ ? distance_ - from : rocks[i] - from;
    
        while(gap < dist && i<size_) {
            cnt++;
            i++;
            gap = i==size_ ? distance_ - from : rocks[i] - from;
        }
        from = i==size_ ? distance_ : rocks[i];
    }
    if(gap < dist) {
        cnt++;
    }
    
    return cnt <= N;
}

int solution(int distance__, vector<int> rocks_, int n) {
    distance_ = distance__;
    rocks = rocks_;
    N = n;
    size_ = rocks.size();
    
    sort(rocks.begin(), rocks.end());

    int l = 0;
    int r = distance_;
    
    // n 이하로 돌 지웠을 때 거리가 최대가 되는 지점
    int m;
    while(l<=r) {
        int m = (l+r)/2;
        
        if(check(m)) {
            l = m+1;
        } else {
            r = m-1;
        }
        
    }
    return l-1;
}