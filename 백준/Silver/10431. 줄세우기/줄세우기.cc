#include <iostream>

using namespace std;

int P;

int arr[20] = {};

int cal_step_back(int stu_num, int h) {
    int small_cnt = 1;
    for (int i = 0; i < stu_num - 1; i++) {
        if (arr[i] < h) small_cnt++;
    }

    return stu_num - small_cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> P;
    while (P--) {
        int x;
        cin >> x;

        int res = 0;
        fill_n(arr, 20, 0);
        for (int num = 0; num < 20; num++) {
            cin >> arr[num];
            res += cal_step_back(num + 1, arr[num]);
        }

        cout << x << ' ' << res << '\n';
    }

    return 0;
}