#include <string>
#include <vector>

#define ll long long

using namespace std;

// q1 + q2

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    vector<int> q = queue1;
    q.insert(q.end(), queue2.begin(), queue2.end());

    ll sum = 0;
    int size = q.size();
    
    for(int i=0; i<size; i++) {
        sum += q[i];
    }
    
    if(sum%2 == 1) return -1;
    
    ll target = sum/2;
    
    int s = 0;
    int e = queue1.size()-1;
    
    ll prefSum = 0;
    for(int i=0; i<=e; i++) {
        prefSum += q[i];
    }
    
    answer = -1;
    int cnt = 0;
    while(s<=e && e<size) {
        if(prefSum == target) {
            answer = cnt;
            break;
        } else if(prefSum < target) {
            cnt++;
            e++;
            if(e==size) break;
            prefSum += q[e];
        } else {
            cnt++;
            prefSum -= q[s];
            s++;
        }
    }
    
    
    return answer;
}