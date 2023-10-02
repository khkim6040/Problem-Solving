#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M, K;
priority_queue<string> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        // Get S and sort ascending order
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        // Use priority queue
        if (pq.size() < K) {
            pq.push(str);
        } else if (pq.size() == K && pq.top() > str) {
            pq.pop();
            pq.push(str);
        }
    }
    // Assemble queue elements
    string answer;
    while (!pq.empty()) {
        string str = pq.top();
        pq.pop();
        answer += str;
    }
    // Sort ascending order
    sort(answer.begin(), answer.end());
    cout << answer;
    return 0;
}