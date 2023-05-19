#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int A[1111111];
vector<int> lis;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    
    lis.push_back(A[0]);
    for(int i=1; i<N; i++) {
        if(A[i] > lis[lis.size()-1]) {
            lis.push_back(A[i]);
        }
        else {
            int pos = lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
            lis[pos] = A[i];
        }
    }
    
    cout << lis.size();
    return 0;
}