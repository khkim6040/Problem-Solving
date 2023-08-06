#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int nums[10];
int answer[10];
bool visited[10]; // 조합이 아닌 수열을 위해

void backTrack(int count) {
    if(count==M) {
        for(int i=0; i<M; i++) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
        return;
    }
    // 중복된 수열 확인하기 위한 변수
    // 수열 자릿수(count)가 바뀌고 처음으로 반복문 들어갈 때는 중복 확인하면 안되므로 -1로 초기화
    int prev_num = -1; 
    for(int i=0; i<N; i++) {
        int cur_num = nums[i];
        // 수열 출력한 뒤 "같은 자릿수"에서 숫자가 같다면 중복되는 수열임
        // prev_num != cur_num로 걸러냄
        if(!visited[i] && prev_num != cur_num) {
            prev_num = cur_num;
            visited[i] = true;
            answer[count] = cur_num;
            backTrack(count+1);
            visited[i] = false;
        }
            
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+N);
    backTrack(0);
    return 0;
}
