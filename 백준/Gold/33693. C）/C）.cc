#include <iostream>


#include <string>

#define INF 2111111111

using namespace std;


int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    while(T--) {
        int c_count = 0;
        // int u_count = 0;
        int cc_count = 0;

        string s;
        string ans_s;
        int ans = 0;
        cin >> s;
        for(char c: s) {
            if(c=='C') {
                ans_s.push_back('C');
                c_count++;
            } else {
                if(c_count) {
                    ans_s.push_back(')');
                    ans++;
                    c_count--;
                } else {
                    ans_s.push_back('C');
                    ans++;
                    c_count++;
                }
            }
        }

        int size = s.size();
        for(int i=size-1; i>=0; i--) {
            char c = ans_s[i];
            if(c=='C') {
                if(i != size-1 && cc_count) {
                    ans_s[i] = '(';
                    cc_count--;
                } else {
                    ans += 2;
                    ans_s[i] = ')';
                    cc_count++;
                }
            } else if(c==')') {
                cc_count++;
            }
        }

        
        cout << ans << '\n';
        for(char c: ans_s) {
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}