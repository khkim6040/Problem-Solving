#include <iostream>
#include <vector>

#define ll long long
#define pll pair<ll, ll>
using namespace std;

char b[10005][555];
int N, M;

bool dfs(int r, int c) {
    if(r<0 || r>=N) return false;
    if(b[r][c] == 'x') return false;
    b[r][c] = 'x';
    if(c == M-2) return true;
    
    return dfs(r-1, c+1) || dfs(r, c+1) || dfs(r+1, c+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> b[i][j];
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++) {
        if(dfs(i, 1)) ans++;
    }

    cout << ans;

    return 0;
}