#include <iostream>
#include <vector>
#define MAX_WEIGHT 80005
using namespace std;

int N, M;
int set[35];
bool isSubset[80005][35]; // [MAX_WEIGHT][N]

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // Input
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> set[i];
    }
    // Fill DP table subset sum and diff
    for(int i=1; i<=MAX_WEIGHT; i++) {
        isSubset[i][0] = false;
    }
    for(int i=0; i<=N; i++) {
        isSubset[0][i] = true;
    }
    for(int j=1; j<=N; j++) {
        for(int i=1; i<=MAX_WEIGHT; i++) {
            isSubset[i][j] = isSubset[i][j-1] || isSubset[i+set[j]][j-1] || isSubset[abs(i-set[j])][j-1];
        }
    }
    // Output
    cin >> M;
    for(int k=0; k<M; k++) {
        int target;
        cin >> target;
        if(isSubset[target][N]) {
            cout << "Y" << ' ';
        }
        else {
            cout << "N" << ' ';
        }
    }   
    return 0;
}