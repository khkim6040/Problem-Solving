#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int N;
int A[1111111];
vector<int> lis;
int position[1111111]; // 완성된 LIS 요소를 역추적하기 위한 요소들이 있는 index 배열 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    
    lis.push_back(A[0]);
    position[0] = 0;
    int length = 1;
    for(int i=1; i<N; i++) {
        if(A[i] > lis[lis.size()-1]) {
            lis.push_back(A[i]);
            position[i] = length;
            length++;
        }
        else {
            int pos = lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
            lis[pos] = A[i];
            position[i] = pos;
        }
    }
    // LIS 작성
    int count = length-1;
    int i = N-1;
    stack<int> answer;
    while(count >= 0) {
        // 넣을 값 순서 && 중복된 위치 안넣게끔
        if(position[i]==count && answer.size()+count==length-1) {
            answer.push(A[i]);
            count--;
        }
        i--;
    }
    // 출력
    cout << length << '\n';
    while(!answer.empty()) {
        cout << answer.top() << ' ';
        answer.pop();
    }
    return 0;
}