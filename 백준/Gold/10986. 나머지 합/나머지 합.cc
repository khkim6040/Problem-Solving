#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

#define pii pair<int, int>

#define TRUE 1
#define FALSE 0

using namespace std;

int N, M;

int A[1000002];
long long comb[1000002];
int cnt[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i=1; i<=N; i++) {
        int x;
        cin >> x;
        A[i] = x%M;
    }

    int sum = 0;
    for(int i=1; i<=N; i++) {
        sum += A[i];
        cnt[sum%M]++;
    }

    comb[1] = 1;
    for(int i=2; i<=N; i++) {
        comb[i] = comb[i-1] + i;
    }

    long long ans = 0;
    ans += comb[cnt[0]];
    for(int i=1; i<M; i++) {
        ans += comb[cnt[i]-1];
    }

    cout << ans;
    
    return 0;
}