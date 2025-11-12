#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define ll long long
#define pii pair<int, int>
#define INF 211111111

using namespace std;

int N;
int NGE[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    stack<int> s;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        s.push(x);
    }

    stack<int> prev;
    int idx = N-1;
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        while(!prev.empty()) {
            int pre = prev.top();
            if(pre <= cur) {
                prev.pop();
            } else {
                NGE[idx--] = pre;
                break;
            }
        }

        if(prev.empty()) {
            NGE[idx--] = -1;
        }

        prev.push(cur);
    }
    
    for(int i=0; i<N; i++) {
        cout << NGE[i] << ' ';
    }

    return 0;
}