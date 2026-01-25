#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int N, M;
int b[111];
int dp[111][111][55]; // dp[i][j][k] = i부터 j까지 범위에서 합이 k개의 구간을 선택했을 때 구간 합의 최댓값
int pref_sum[111][111];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        cin >> b[i];
    }

    for(int k=1; k<=N; k++) {
        for(int i=0; i<N; i++) {
            int end = i+k-1;
            if(k==1) {
                pref_sum[i][end] = b[i];
                continue;
            }

            pref_sum[i][end] = pref_sum[i][end-1] + b[end];
        }
    }

    int INF = 111111111;
    fill_n(&dp[0][0][0], 111*111*55, -INF);

    // 길이
    for(int k=1; k<=N; k++) {
        // 시작 지점
        for(int i=0; i<N; i++) {
            int end = i+k-1;
            if(end >= N) continue;

            if(k==1) {
                dp[i][end][1] = b[i];
                continue;
            }

            dp[i][end][1] = max({dp[i][end-1][1], dp[i+1][end][1], pref_sum[i][end]});
        }
    }


    
    // 구간 개수(2~M)
    for(int cnt=2; cnt<=M; cnt++) {
        // 길이
        for(int k=3; k<=N; k++) {
            // 시작 지점
            for(int i=0; i<N; i++) {
                int end = i+k-1;
                if(end >= N) continue;
                
                // 끊는 지점. 기준으로 앞은 1개 구간, 뒤는 구간 개수-1 로 연산
                for(int j=i+1; j<end; j++) {
                    dp[i][end][cnt] = max(dp[i][end][cnt], dp[i][j-1][1]+dp[j+1][end][cnt-1]); 
                }
            }
        }
    }

    cout << dp[0][N-1][M];
    return 0;
}