#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Snake {
    int y = 1;
    int x = 1;
    int direction = 0;  // right == 0, down == 1, left == 2, up == 3
    int length = 1;
};

int N, K, L;
int board[105][105];
queue<pair<int, int>> q;  // {time, direction}
int time_consumed;
int visited_time[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    fill_n(&visited_time[0][0], 105 * 105, -1);
    for (int i = 0; i < K; i++) {
        int y, x;
        cin >> y >> x;
        board[y][x] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int time, direction;
        char dir;
        cin >> time >> dir;
        direction = dir == 'D' ? 1 : -1;
        q.push({time, direction});
    }

    pair<int, int> next_direction = q.front();
    q.pop();
    Snake s;
    while (true) {
        time_consumed++;
        // move
        if (s.direction == 0) {
            s.x++;
        } else if (s.direction == 1) {
            s.y++;
        } else if (s.direction == 2) {
            s.x--;
        } else if (s.direction == 3) {
            s.y--;
        }
        // check collision
        // cross limits
        if (s.x < 1 || s.x > N || s.y < 1 || s.y > N) {
            break;
        }
        // bump itself
        if (visited_time[s.y][s.x] != -1 && time_consumed - visited_time[s.y][s.x] <= s.length) {
            break;
        }
        // earn apple
        if (board[s.y][s.x] == 1) {
            s.length++;
            board[s.y][s.x] = 0;
        }
        // mark visited time
        visited_time[s.y][s.x] = time_consumed;
        // change direction
        if (time_consumed == next_direction.first) {
            s.direction = (s.direction + next_direction.second + 4) % 4;
            if (!q.empty()) {
                next_direction = q.front();
                q.pop();
            }
        }
    }

    cout << time_consumed;

    return 0;
}