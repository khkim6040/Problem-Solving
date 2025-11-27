#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N, K;
string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K >> S;

    stack<int> s;
    for(char cc: S) {
        int cur = cc - '0';
        if(s.empty()) {
            s.push(cur);
            continue;
        }

        while(!s.empty() && s.top() < cur && K>0) {
            s.pop();
            K--;
        }
        s.push(cur);
    }

    while(K>0) {
        s.pop();
        K--;
    }

    vector<int> ans(s.size());
    int idx = s.size()-1;
    while(!s.empty()) {
        ans[idx--] = s.top();
        s.pop();
    }

    for(int e: ans) {
        cout << e;
    }


    return 0;
}