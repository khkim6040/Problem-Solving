#include <iostream>
#include <vector>
#include <cmath>
#define INF 1000000
using namespace std;
struct Point {
    double x, y;
};

int N;
vector<Point> points;
double dist[105];
bool selected[105];

int getArgMin() {
    double min = INF;
    int min_idx = -1;
    for(int i=0; i<N; i++) {
        if(!selected[i] && dist[i]<min) {
            min = dist[i];
            min_idx = i;
        }
    }
    return min_idx;
}

double getDist(Point a, Point b) {
    return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) {
        double x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    // Prim
    // Initialize
    dist[0] = 0;
    fill(dist, dist+105, INF);
    selected[0] = true;
    for(int i=0; i<N; i++) {
        if(selected[i]) continue;
        double d = getDist(points[0], points[i]);
        if(d < dist[i]) {
            dist[i] = d;
        }
    }    
    // Do prim
    double answer = 0;
    while(true) {
        int index = getArgMin();
        if(index==-1) break;
        
        selected[index] = true;
        answer += dist[index];
        for(int i=0; i<N; i++) {
            if(selected[i]) continue;
            double d = getDist(points[index], points[i]);
            if(d < dist[i]) {
                dist[i] = d;
            }
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << answer;
    return 0;
}