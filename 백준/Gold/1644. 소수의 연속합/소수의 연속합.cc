#include <iostream>
#include <vector>
using namespace std;
#define MAX 4000000

vector<int> p;
bool is_prime[4000001];
int s, e;
long long ans, sum;
int N;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    fill_n(is_prime, 4000001, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX; i++) {
        if (is_prime[i]) {
            p.push_back(i);
            for (int j = i * 2; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
    // 마지막 표시
    p.push_back(MAX + 1);

    sum = p[s];
    cin >> N;
    while (e <= s) {
        if (sum == N) {
            ans++;
            s++;
            sum += p[s];
        } else if (sum < N) {
            s++;
            sum += p[s];
        } else if (sum > N) {
            sum -= p[e];
            e++;
        }
    }

    cout << ans;
    return 0;
}