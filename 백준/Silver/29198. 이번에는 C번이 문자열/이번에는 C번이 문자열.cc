#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int N, M, K;
struct Input {
   string str;
   int size;
   bool operator<(const Input& other) const {
      return size < other.size;
   }
};
priority_queue<Input> pq;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> N >> M >> K;
   for (int i = 0; i < N; i++) {
      // Get S and calculate its size
      int sum = 0;
      string str;
      cin >> str;
      for (char c : str) {
         sum += int(c);
      }
      // Use priority queue
      if (pq.size() < K) {
         pq.push({str, sum});
      } else if (pq.size() == K && pq.top().size > sum) {
         pq.pop();
         pq.push({str, sum});
      }
   }
   // Assemble all queue elements
   string answer;
   while (!pq.empty()) {
      string str = pq.top().str;
      pq.pop();
      answer += str;
   }
   // Sort ascending order
   sort(answer.begin(), answer.end());
   cout << answer;
   return 0;
}