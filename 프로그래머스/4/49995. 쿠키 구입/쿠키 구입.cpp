#include <string>
#include <vector>

using namespace std;

// l, r, m 포인터 3개
// 0~N-1, 1~N-1, ... , N-2~N-1 까지 출발 지점(=l)을 늘려감 O(N)
// 한 구간에서 m, r을 m < r 유지시키면서 끝까지 늘림 O(N)
    // 각 구간마다 반반 나눠떨어지게 하는 지점은 최대 하나임. 유일함. 
    // 즉, 매 중간 지점 찾는 시간이 O(N)이 아니라 O(1)이 됨. 즉 전체적으로 O(N)에 떨어짐
// => O(N^2)

int solution(vector<int> c) {
    int answer = 0;
    
    int l, m = 0;
    int r = 1;
    
    int N = c.size();
    
    for (int l=0; l<N-1; l++) {
        int m = l;
        int r = l+1;
        
        int sum = c[l];
        int prefSum = c[l];
        for(int r=l+1; r<N; r++) {
            sum += c[r];
            // l~r 에서 절반이 되는 m 값이 있는지 탐색
            while(2*(prefSum+c[m+1]) <= sum) {
                prefSum += c[m+1];
                m++;
            }
            
            // 같은지 확인
            if(2*prefSum == sum) {
                answer = max(answer, prefSum);
            }
        }
        
        
        
    }
    
    
    return answer;
}