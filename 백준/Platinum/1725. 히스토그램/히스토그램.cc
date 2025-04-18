// Min value가 아닌 arr 상에서 Min value의 index를 저장하는 seg tree

// 1-N에서 min value index를 찾고 넓이를 계산,
    // 1-(min value index-1)과 (min value index+1)-N 의 범위에 대한 같은 계산 반복
    // 어떻게 min value index 전후로 나눠 분할해 탐색하는 게 최적해를 보장하는가? 
    // 해당 범위에 min value를 갖는 index가 여러 개일 수도 있는데 임의로 나누는게 맞나?
        // 만약 min value가 여러 개 있다면 나누기 전이 나눈 후보다 무조건 커야 한다. 2 2 2 => 6, 어디를 기준으로 나누든 나누기 전보다 넓이가 작음


#include <iostream>
#include <algorithm>

using namespace std;

int t[400004]; // min value index를 갖는 seg tree
int arr[100004];
int N;

void update(int node, int s, int e, int idx, int v) {
    if(s==e) {
        arr[idx] = v;
        t[node] = idx;
        return;
    }

    int mid = (s+e)/2;
    if(idx<=mid) {
        update(node*2, s, mid, idx, v);
    } else {
        update(node*2+1, mid+1, e, idx, v);
    }

    t[node] = arr[t[node*2]] < arr[t[node*2+1]] ? t[node*2] : t[node*2+1];
 }

int find(int node, int s, int e, int l, int r) {
    if(l>e || r<s) {
        return 0;
    }
    if(l<=s && e<=r) {
        return t[node];
    }

    int mid = (s+e)/2;
    int idx1 = find(node*2, s, mid, l, r);
    int idx2 = find(node*2+1, mid+1, e, l, r);
    return arr[idx1] < arr[idx2] ? idx1 : idx2;
}

int find_max(int l, int r) {
    if(l>r) {
        return -1;
    }

    int idx = find(1, 1, N, l, r);
    int ans = (r-l+1)*arr[idx];
    ans = max({ans, find_max(l, idx-1), find_max(idx+1, r)});
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    arr[0] = 2111111111;
    for(int i=1; i<=N; i++) {
        int x;
        cin >> x;
        update(1, 1, N, i, x);
    }

    cout << find_max(1, N);


    return 0;
}
 