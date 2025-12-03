#include <iostream>
#include <string>

#define ll long long
#define INF 211111111111
using namespace std;

int N;
string S;
int M; // 연산자의 수
ll ans = -INF;
bool checked[30];

ll cal(ll a, ll b, char op) {
    if(op == '+') {
        return a + b;
    } else if(op == '-') {
        return a - b;
    } else if(op == '*') {
        return a * b;
    }
}

ll calculate() {
    // for(int i=0; i<N; i++) {
    //     cout << checked[i] << ' ';
    // }
    // cout << '\n';

    ll ret = S[0] - '0';
    int cur = 1;
    while(cur<N) {
        int next = cur+2;
        if(next >= N || !checked[next]) {
            ret = cal(ret, S[cur+1]-'0', S[cur]);
        } else {
            ll tmp = cal(S[next-1]-'0', S[next+1]-'0', S[next]);
            ret = cal(ret, tmp, S[cur]);
            cur+=2;
        }
        cur+=2;
    }

    return ret;
}

void comb(int cur) {
    if(cur == N || cur == N+2) {
        return;
    }

    for(int i=cur; i<N; i=i+2) {
        checked[i] = true;
        ll tmp = calculate();
        // cout << tmp << '\n';
        ans = max(ans, tmp);
        comb(i+4); // 바로 다음 연산자(+2)는 불가능하므로
        checked[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;

    M = N/2;

    if(N==1) {
        cout << S[0]-'0';
        return 0;
    }

    comb(1); // 첫 번째 연산자부터 시작
    
    cout << ans;

    return 0;
}