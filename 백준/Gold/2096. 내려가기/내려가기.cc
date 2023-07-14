#include <iostream>
#include <algorithm>
using namespace std;

int N;
int max_dp[5];
int min_dp[5];
int arr[5][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    max_dp[0] = max_dp[4] = -2111111111;
    min_dp[0] = min_dp[4] = 2111111111;
    for (int i = 1; i <= 3; i++)
    {
        int x;
        cin >> x;
        max_dp[i] = min_dp[i] = x;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            int x;
            cin >> x;
            arr[j][0] = arr[j][1] = x;
        }

        for (int j = 1; j <= 3; j++)
        {
            arr[j][0] += max({max_dp[j - 1], max_dp[j], max_dp[j + 1]});
            arr[j][1] += min({min_dp[j - 1], min_dp[j], min_dp[j + 1]});
        }

        max_dp[1] = arr[1][0];
        max_dp[2] = arr[2][0];
        max_dp[3] = arr[3][0];
        min_dp[1] = arr[1][1];
        min_dp[2] = arr[2][1];
        min_dp[3] = arr[3][1];
    }

    cout << max({max_dp[1], max_dp[2], max_dp[3]}) << ' ' << min({min_dp[1], min_dp[2], min_dp[3]});
    return 0;
}