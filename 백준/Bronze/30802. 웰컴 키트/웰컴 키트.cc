#include <iostream>
using namespace std;

int N, T, P;
int clothes[6];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int c_max = 0;
    for (int i = 0; i < 6; i++) {
        cin >> clothes[i];
        c_max = max(c_max, clothes[i]);
    }
    cin >> T >> P;
    int t_ans = 0;
    for (int i = 0; i < 6; i++) {
        t_ans += (clothes[i] / T) + (clothes[i] % T ? 1 : 0);
    }
    cout << t_ans << '\n';
    cout << N / P << ' ' << N % P;
    return 0;
}