#include <iostream>
#include <queue>
using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    int prev_height;
    cin >> prev_height;

    priority_queue<int, vector<int>, greater<int>> top_K_diff;
    long long int sum_of_diff = 0;
    for(int i=1; i<N; i++) {
        int cur_height;
        cin >> cur_height;

        int diff = cur_height - prev_height;
        prev_height = cur_height;
        sum_of_diff += diff;

        if(top_K_diff.size() < K-1) {
            top_K_diff.push(diff);
        }
        else if(top_K_diff.size() > 0 && top_K_diff.size() == K-1 && top_K_diff.top() < diff) {
            top_K_diff.pop();
            top_K_diff.push(diff);
        }
    }

    while(!top_K_diff.empty()) {
        sum_of_diff -= top_K_diff.top();
        top_K_diff.pop();
    }

    cout << sum_of_diff;
    return 0;
}