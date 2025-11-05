#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    while(num<=n) {
        answer++;
        num += (w-(num-1)%w)*2 - 1;
    }
    return answer;
}