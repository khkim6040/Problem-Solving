#include <iostream>

using namespace std;

int N, K, X;

int A[505];
int B[505];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    for(int i=0; i<N; i++) {
        cin >> B[i];
    }

    int AMax = 0;
    for(int k=0; k<N; k++) {
        int dp[505] = {0, };
        for(int i=0; i<N; i++) {
            int s = (i+k)%N;
            dp[i] = 1;
            for(int j=0; j<i; j++) {
                if(A[s] > A[(j+k)%N]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        // cout << dp[N-1] << '\n';
        AMax = max(AMax, dp[N-1]);
    }

    
    int BMax = 0;
    for(int k=0; k<N; k++) {
        int dp[505] = {0, };
        for(int i=0; i<N; i++) {
            int s = (i+k)%N;
            dp[i] = 1;
            for(int j=0; j<i; j++) {
                if(B[s] > B[(j+k)%N]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        BMax = max(BMax, dp[N-1]);
    }

    if(AMax > BMax) {
        cout << "YJ Win!";
    } else if(AMax < BMax) {
        cout << "HG Win!";
    } else {
        cout << "Both Win!";
    }

    return 0;
}



// int A[200005];

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> N >> K >> X;

//     for(int i=1; i<=N; i++) {
//         cin >> A[i];
//     }

//     // 뒤에 휴가
//     int pref_sum = 0;
//     int ans = -1;
//     for(int i=1; i<N; i++) {
//         pref_sum += A[i]*X;
//         if(pref_sum >= K) {
//             ans = max(ans, N-i);
//             break;
//         }
//     }

//     // 앞에 휴가
//     pref_sum = 0;
//     for(int i=N; i>1; i--) {
//         pref_sum += A[i];
//         if(pref_sum >= K) {
//             ans = max(ans, i-1);
//             break;
//         }
//     }

//     // 중간에 휴가
//     int s = 1;
//     int e = N;
//     pref_sum = 0;
//     while(s<e) {
//         if(A[s]*X > A[e]) {
//             pref_sum += A[s]*X;
//             s++;
//         } else {
//             pref_sum += A[e];
//             e--;
//         }

//         if(pref_sum >= K) {
//             ans = max(ans, e-s+1);
//             break;
//         }
//     }

//     cout << ans;
    
//     return 0;
// }

