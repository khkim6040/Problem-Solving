#include <string>
#include <vector>
#include <algorithm>

#define ll long long
#define CNT 26
using namespace std;


string toString(ll x) {
    // 1~26: a~z
    // 27~52: aa~az
    string ret = "";
    while(x > 0) {
        x--;
        ll div = x/CNT;
        int rem = x%CNT;
        ret += (char)('a'+rem);
        x/=CNT;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

ll toInt(string s) {
    int size = s.size();
    ll ret = 0;
    for(int i=0; i<size; i++) {
        int n = s[i] - 'a';
        ret *= CNT;
        ret += n+1;
    }
    return ret;
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    
    // bans를 int로 변환
    vector<ll> b;
    for(string ban: bans) {
        b.push_back(toInt(ban));
    }
    sort(b.begin(), b.end());
    
    // for ban: bans
    for(auto ban: b) {
        if(n>=ban) {
            n++;
        } else {
            break;
        }
    }
    
    return toString(n);
}