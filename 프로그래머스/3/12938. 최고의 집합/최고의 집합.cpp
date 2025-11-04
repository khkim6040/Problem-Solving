#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    vector<int> no;
    no.push_back(-1);
    
    int div = s/n;
    int rem = s%n;
    
    // 같은 몫, 나머지는 1씩 분배?
    if(div == 0) return no;
    
    while(n) {
        if(n>rem) {
            answer.push_back(div);
        } else {
            answer.push_back(div+1);    
        }
        n--;
    }
    return answer;
}