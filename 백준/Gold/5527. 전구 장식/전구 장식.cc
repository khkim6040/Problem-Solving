#include <iostream>
#include <vector>
using namespace std;

int N;
int pre, cur;
vector<int> consecutive_counts;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int count = 1;
    cin >> pre;
    for (int i = 1; i < N; i++) {
        cin >> cur;
        if (pre == cur) {
            consecutive_counts.push_back(count);
            count = 1;
        } else {
            count++;
        }
        pre = cur;
    }
    consecutive_counts.push_back(count);

    int size = consecutive_counts.size();
    if (size == 1) {
        cout << consecutive_counts[0];
    } else if (size == 2) {
        cout << consecutive_counts[0] + consecutive_counts[1];
    } else {
        int max_consecutive_count = 0;
        for (int i = 1; i < size - 1; i++) {
            max_consecutive_count = max(max_consecutive_count,
                                        consecutive_counts[i - 1] + consecutive_counts[i] + consecutive_counts[i + 1]);
        }
        cout << max_consecutive_count;
    }

    return 0;
}