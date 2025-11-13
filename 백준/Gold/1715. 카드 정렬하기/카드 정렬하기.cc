#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define ll long long
#define pii pair<int, int>
#define INF 211111111

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        q.push(x);
    }


    int ans = 0;
    while(q.size() > 1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans += a+b;
        q.push({a+b});
    }

    cout << ans;
     
    return 0;
}