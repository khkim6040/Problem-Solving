#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define ll long long 
#define SIZE 26

using namespace std;

string mapper = "abcdefghijklmnopqrstuvwxyz";
vector<ll> ibans;

ll strToInt(string s) {
    ll ret = 0;
    int size = s.size();
    for(int i=0; i<size; i++) {
        ret *= SIZE;
        ret += (s[i] - 'a' + 1);
    }
    return ret;
}

string intToStr(ll x) {
    string ret = "";
    
    while(x) {
        x--;
        char alp = mapper[x%(SIZE)];
        ret.push_back(alp);
        x /= SIZE;
        
    }
    
    reverse(ret.begin(), ret.end());
    
    return ret;
}


string solution(long long n, vector<string> bans) {
    // a-z 개수 26
    // aa-zz 개수 26*26
    // 각 레벨 별 개수 26^h
    // bans 문자열들을 숫자로 변환
    // n 보다 작은 bans 가 없을 때까지 반복
        // 차이만큼 n에 더함
    // n을 문자열로 변환
    
    
    for(string s: bans) {
        ibans.push_back(strToInt(s));
    }
    sort(ibans.begin(), ibans.end());
    
    int bansSize = bans.size();
    for(int i=0; i<bansSize; i++) {
        if(n >= ibans[i]) {
            n++;
        } else {
            break;
        }
    }
    
    return intToStr(n);
}