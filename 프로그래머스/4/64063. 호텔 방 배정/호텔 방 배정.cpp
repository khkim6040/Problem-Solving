#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

#define ll long long
using namespace std;

unordered_map<ll, ll> parent;

ll find(ll u) {
    if(parent[u] == 0) return u;

    parent[u] = find(parent[u]);
    
    return parent[u];
}

void set(ll u) {
    parent[u] = find(u)+1;
}


vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    vector<ll> vec;
    
    // lower bound 찾기
    
    // if mapper[lowerBound] < num
        // vec.push_back(num)
        // mapper[num] = num;
        // answer.push_back(num)
    // else
        // answer.push_back(mapper[lowerBound]++)
    
    
    for(ll num: room_number) {
        ll p = find(num);
        if(num == p) {
            set(num);
            answer.push_back(num);
        } else {
            set(p);
            answer.push_back(p);
        }
        // for(int i=1; i<=6; i++) {
        //     cout << parent[i] << ' ';
        // }
        // cout << '\n';
    }
    

    
    return answer;
}