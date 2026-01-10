#include <iostream>

using namespace std;

int N;
char b[11111][11111]; // 3072
int W, H;

void draw(int n, int r, int c) {
    if(n==3) {
        b[r][c] = '*';
        b[r+1][c-1] = '*';
        b[r+1][c+1] = '*';
        b[r+2][c-2] = '*';
        b[r+2][c-1] = '*';
        b[r+2][c] = '*';
        b[r+2][c+1] = '*';
        b[r+2][c+2] = '*';
        return;
    }

    draw(n/2, r, c);
    draw(n/2, r+n/2, c-n/2);
    draw(n/2, r+n/2, c+n/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    // 새로 길이: N
    H = N;
    // 가로 길이: 2*N - 1
    W = 2*N-1;
    
    draw(N, 0, N-1);

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(b[i][j] == '*') cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}