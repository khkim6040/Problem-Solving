#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Point {
    long long x;
    long long y;
    bool const operator<(const Point other) {
        if (y == other.y) {
            return x < other.x;
        }
        return y < other.y;
    }
};

int N;
vector<Point> points;

bool is_CCW(Point pre, Point cur, Point next) {
    long long s = pre.x * cur.y + cur.x * next.y + next.x * pre.y;
    s -= (pre.y * cur.x + cur.y * next.x + next.y * pre.x);

    return s > 0;
}

int make_convex_hull() {
    stack<Point> s;
    for (Point next : points) {
        while (s.size() >= 2) {
            Point cur = s.top();
            s.pop();
            Point pre = s.top();
            if (is_CCW(pre, cur, next)) {
                s.push(cur);
                break;
            }
        }
        s.push(next);
    }
    return s.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    // right half convex hull
    sort(points.begin(), points.end());
    int right_hull_size = make_convex_hull();
    // left half convex hull
    reverse(points.begin(), points.end());
    int left_hull_size = make_convex_hull();

    cout << right_hull_size + left_hull_size - 2;
    return 0;
}