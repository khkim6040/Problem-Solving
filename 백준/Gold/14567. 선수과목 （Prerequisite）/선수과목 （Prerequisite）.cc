#include <iostream>
using namespace std;

int N, M;
int dp[1005];
bool is_required_to[1005][1005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int s, e;
        cin >> s >> e;
        is_required_to[s][e] = true;
    }        


    for(int i=1; i<=N; i++) {
        dp[i] = 1;
        int max_required_semester = 1;
        for(int j=1; j<i; j++) {
            if(is_required_to[j][i]) {
                max_required_semester = max(max_required_semester, dp[j]+1);
            }
        }
        dp[i] = max_required_semester;
    }

    for(int i=1; i<=N; i++) {
        cout << dp[i] << ' ';
    }
    return 0;
}