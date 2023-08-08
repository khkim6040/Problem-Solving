#include <iostream>
using namespace std;

int N, K;
int pt1, pt2, cnt, len, ans;
int nums[50005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    for(int i=0; i<N; i++) {
        cin >> nums[i];
    }
    
    while(pt2<N) {
        if(nums[pt2]%2==0) {
            len++;
            pt2++;
        }
        else {
            if(cnt==K) {
                ans = max(ans, len);
                while(nums[pt1++]%2==0) {
                    len--;
                }
                cnt--;
            }
            else {
                cnt++;
                pt2++;
            }
        }
    }
    ans = max(ans, len);
    
    cout << ans;
    return 0;
}
