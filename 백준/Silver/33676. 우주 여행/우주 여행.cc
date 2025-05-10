#include <iostream>

using namespace std;

int N, M, K, L;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K >> L;

    if(N+M-2 <= L && (L-(N+M-2))%2==0) {
        for(int i=0; i<N-1; i++) {
            cout << "D";
        }

        for(int i=0; i<M-1; i++) {
            cout << "R";
        }

        for(int i=0; i<(L-(N+M-2))/2; i++) {
            cout << "LR";
        }
    } else {
        cout << -1;
    }


    return 0;
}