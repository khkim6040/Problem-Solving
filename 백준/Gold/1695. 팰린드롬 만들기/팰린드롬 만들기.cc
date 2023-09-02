#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dp[5005][5005]; 
vector<int> nums;
vector<int> reversed_nums;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
        reversed_nums.push_back(x);
        
    }    

    reverse(reversed_nums.begin(), reversed_nums.end());
    // for 1baesd
    nums.insert(nums.begin(), -1);
    reversed_nums.insert(reversed_nums.begin(), -1);

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(nums[i] == reversed_nums[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << N-dp[N][N];
    return 0;

}