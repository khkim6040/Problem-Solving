#include <iostream>
using namespace std;

int N, K;
int stones[5002];
bool is_possible[5002];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    for(int i=1; i<=N; i++) {
        cin >> stones[i];  
    }
    
    is_possible[1] = true;
    for(int i=2; i<=N; i++) {
        is_possible[i] = false;
        for(int j=1; j<i; j++) {
            if(!is_possible[j]) continue;
            if((i-j)*(1+abs(stones[i]-stones[j])) <= K) {
                is_possible[i] = true;
            }
        }
    }

    if(is_possible[N]) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}