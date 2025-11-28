#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
stack<int> s;
int cnt[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        s.push(x);
    }


    stack<int> tmp;
    stack<int> answer;
    while(!s.empty()) {
        int cur = s.top();
        s.pop();

        while(!tmp.empty() && cnt[tmp.top()] <= cnt[cur]) {
            tmp.pop();
        }

        if(tmp.empty()) {
            answer.push(-1);
        } else {
            answer.push(tmp.top());
        }
        tmp.push(cur);
    }

    while(!answer.empty()) {
        cout << answer.top() << ' ';
        answer.pop();
    }

    return 0;
}