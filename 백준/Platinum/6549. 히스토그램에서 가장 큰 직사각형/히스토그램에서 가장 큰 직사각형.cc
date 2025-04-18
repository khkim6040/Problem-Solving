#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define MAX_HEIGHT 2000000000

int N;
vector<ll> arr;
vector<ll> tree;
ll max_area;

int init(int index, int start, int end) {
    if (start == end) {
        return tree[index] = start;
    }

    int mid = (start + end) / 2;
    int left_index = init(2 * index, start, mid);
    int right_index = init(2 * index + 1, mid + 1, end);
    return tree[index] = arr[left_index] < arr[right_index] ? left_index : right_index;
}

int find(int index, int start, int end, const int &from, const int &to) {
    if (start > to || end < from) {
        return 0;
    }
    if (start >= from && end <= to) {
        return tree[index];
    }

    int mid = (start + end) / 2;
    int left_index = find(2 * index, start, mid, from, to);
    int right_index = find(2 * index + 1, mid + 1, end, from, to);
    return arr[left_index] < arr[right_index] ? left_index : right_index;
}

ll findMaxArea(int from, int to) {
    if (from > to) {
        return -1;
    }
    int min_height_index = find(1, 1, N, from, to);
    max_area = max({max_area, arr[min_height_index] * (to - from + 1), findMaxArea(from, min_height_index - 1), findMaxArea(min_height_index + 1, to)});

    return max_area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N) {
        if (N == 0) break;
        arr.assign(N + 1, 0);
        arr[0] = MAX_HEIGHT; // find의 if (start > to || end < from) 조건에 걸렸을 때 범위를 벗어난 표시하기위해 
        tree.assign(4 * N, 0);
        max_area = 0;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        init(1, 1, N);
        cout << findMaxArea(1, N) << '\n';
    }

    return 0;
}