#include <iostream>
using namespace std;

int N;
int counts[10];      // 0~9까지 개수
int place_value[9];  // 자릿수

// page 값과 고려하는 자릿수에 따라 counts를 올려줌
void calculate(int page, int digit) {
    while (page) {
        // page=1234이고 1의 자릿수를 고려한다면(digit==1) 1, 2, 3, 4 각각 1씩 올라감
        // page=1234이고 10의 자릿수를 고려한다면(digit==10) 실제로는 1234x일 것이고 x는 0~9까지 총 10개가 올 수 있으므로 1, 2, 3, 4 각각 10씩 올라감
        // page=1234이고 100의 자릿수를 고려한다면(digit==100) 실제로는 1234xx일 것이고 x는 0~9까지 총 10*10개가 올 수 있으므로 1, 2, 3, 4 각각 100씩 올라감
        counts[page % 10] += digit;
        page /= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int digit = 1;  // 반복문 속에서 어느 현재 어느 자릿수를 고려하는지(일의 자릿수=1, 십의 자릿수=10 ...)
    int start, end;
    start = 1;  // 1부터
    end = N;    // N까지 페이지 값
    while (true) {
        // start를 끝이 0이 될 때까지 ++하며 거쳐가는 페이지 counts에 반영함
        // start가 end보다 커지는 경우는 가장 마지막 자릿수까지 모두 비교했을 때밖에 없음
        while (start <= end && start % 10 != 0) {
            calculate(start, digit);
            start++;
        }
        // 모두 고려했으므로 반복문 종료
        if (start > end)
            break;
        // end를 끝이 9가 될 때까지 --하며 거쳐가는 페이지 counts에 반영함
        // end >= start 조건으로 start에서 고려한 페이지 중복해서 고려하지 않게 함
        while (end >= start && end % 10 != 9) {
            calculate(end, digit);
            end--;
        }
        // 두 수의 일의 자릿수 제외한 값 차이(end/10 - start/10 + 1)에다 digit 곱한 것만큼 0~9의 수 증가시켜야 함
        // 넓은 범위에서 calculate를 적용했다고 생각하면 됨
        int page_diff = end / 10 - start / 10 + 1;
        for (int i = 0; i < 10; i++) {
            counts[i] += page_diff * digit;
        }
        // 고려하는 자릿수 증가시키고
        digit *= 10;
        // 다음 자릿수를 고려함
        start /= 10;
        end /= 10;
    }

    for (int i = 0; i < 10; i++) {
        cout << counts[i] << ' ';
    }

    return 0;
}