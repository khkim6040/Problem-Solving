#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M;
int A[1005], B[1005];
vector<int> prefix_A, prefix_B;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // A, B의 모든 가능한 구간합을 prefix_A, prefix_B에 저장(1000*1000 size)
    cin >> T >> N;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        for(int j=0; j<=i; j++) {
            A[j] += x;
            prefix_A.push_back(A[j]);
        }
    }
    cin >> M;
    for(int i=0; i<M; i++) {
        int x;
        cin >> x;
        for(int j=0; j<=i; j++) {
            B[j] += x;
            prefix_B.push_back(B[j]);
        }
    }
    // 정렬 후 모든 A의 부배열의 합 a에 대해 T-a가 B의 부배열의 합에 얼마나 많이 존재하는지 확인
    sort(prefix_B.begin(), prefix_B.end());
    long long answer = 0;
    for(int a: prefix_A) {
        auto range = equal_range(prefix_B.begin(), prefix_B.end(), T-a);
        answer += range.second - range.first;
    }
    
    cout << answer;
    return 0;
}