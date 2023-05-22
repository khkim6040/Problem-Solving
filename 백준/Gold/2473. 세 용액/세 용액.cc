#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

int N;
vector<int> nums;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    
    ll min_value = 3333333333;
    int min_eles[3] = {0, };
    for(int k=0; k<N; k++) {
        int cur_value = nums[k];
        int i=0; int j=N-1;
        while(i<j) {
            if(i==k) {
                i++;
            }
            else if(j==k) {
                j--;
            }
            else {
                int two_sum = nums[i]+nums[j];
                ll total_sum = 1ll*two_sum+cur_value;
                if(min_value > abs(total_sum)) {
                    min_value = abs(total_sum);
                    min_eles[0] = nums[i];
                    min_eles[1] = nums[j];
                    min_eles[2] = nums[k];
                }
                if(total_sum > 0) {
                    j--;
                }
                else if(total_sum < 0) {
                    i++;
                }
                else {
                    break;
                }
            }
        }
    }
    
    sort(min_eles, min_eles+3);
    for(int i=0; i<3; i++) {
        cout << min_eles[i] << ' ';
    }
    return 0;
}