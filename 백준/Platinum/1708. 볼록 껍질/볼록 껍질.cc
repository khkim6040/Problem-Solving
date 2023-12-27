#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Point {
    long long x;
    long long y;
    bool is_used;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;
        points.push_back({x, y, false});
    }

    // right half convex hull
    sort(points.begin(), points.end());
    stack<Point> s1;
    for (Point next : points) {
        while (s1.size() >= 2) {
            Point cur = s1.top();
            cur.is_used = false;
            s1.pop();
            Point pre = s1.top();
            if (is_CCW(pre, cur, next)) {
                cur.is_used = true;
                s1.push(cur);
                break;
            }
        }
        next.is_used = true;
        s1.push(next);
    }

    // left half convex hull
    reverse(points.begin(), points.end());
    // should consider first&last point
    points.front().is_used = false;
    points.back().is_used = false;
    stack<Point> s2;

    for (Point next : points) {
        // if point is already used in left convex hall, ignore it
        if (next.is_used)
            continue;

        while (s2.size() >= 2) {
            Point cur = s2.top();
            cur.is_used = false;
            s2.pop();
            Point pre = s2.top();
            if (is_CCW(pre, cur, next)) {
                cur.is_used = true;
                s2.push(cur);
                break;
            }
        }
        next.is_used = true;
        s2.push(next);
    }

    int answer = s1.size() + s2.size() - 2;
    cout << answer;
    return 0;
}