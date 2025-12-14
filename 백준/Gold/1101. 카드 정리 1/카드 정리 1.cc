#include <iostream>
#include <vector>

using namespace std;

int N, M;

bool is_one[55]; //is_one[i] = 숫자 i가 적힌 카드만 담겨있는 박스가 존재하는지 여부

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int ans = 0;
    for(int i=0; i<N; i++) {
        vector<int> v(M);
        for(int j=0; j<M; j++) {
            cin >> v[j];
        }
        int val = -1;
        int cnt = 0;
        for(int j=0; j<M; j++) {
            int x = v[j];
            if(x==0) continue;
            val = j;
            cnt++;
            if(cnt == 2) {
                ans++;
                break;
            }
        }
        if(cnt == 1) {
            if(is_one[val]) {
                ans++;
            } else {
                is_one[val] = true;
            }
        }
    }

    cout << max(0, ans-1);


    return 0;
}