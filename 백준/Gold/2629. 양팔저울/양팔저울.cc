#include <iostream>
#include <vector>
#define MAX_WEIGHT 80005
using namespace std;

int N, M;
int set[35];
bool isSubset[35][MAX_WEIGHT]; // [N][MAX_WEIGHT]

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // Input
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> set[i];
    }
    // Fill DP table subset sum and diff
    for(int i=1; i<=MAX_WEIGHT; i++) {
        isSubset[0][i] = false;
    }
    for(int i=0; i<=N; i++) {
        isSubset[i][0] = true;
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=MAX_WEIGHT; j++) {
            isSubset[i][j] = isSubset[i-1][j] || isSubset[i-1][j+set[i]] || isSubset[i-1][abs(j-set[i])];
        }
    }
    // Output
    cin >> M;
    for(int k=0; k<M; k++) {
        int target;
        cin >> target;
        if(isSubset[N][target]) {
            cout << "Y" << ' ';
        }
        else {
            cout << "N" << ' ';
        }
    }   
    return 0;
}