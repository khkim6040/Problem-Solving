#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M;
int flag = false;

struct Trie {
    bool finish;
    Trie* Node[26];
    Trie() {
        finish = false;
        for(int i=0; i<10; i++) {
            Node[i] = NULL;
        }
    }

   void insert(string& str, int idx) {
        int cur = str[idx] - '0';
        // if(idx==str.size()-1) {
        //     if(Node[cur]!=NULL) {
        //         flag = true;
        //     }
        // }
        
        if(Node[cur]==NULL) Node[cur] = new Trie();
        if(idx==str.size()-1) {
            // cout << "FINI " << str << ' ' << idx << ' ' << cur << '\n';
            if(finish) {
                flag = true;
            }

            Node[cur]->finish = true;
            return;
        } else {
            if(finish) {
                flag = true;
            }
            Node[cur]->insert(str, idx+1);
        }
    }

    // bool find(string& str, int idx) {
    //     int cur = str[idx] - '0';


    //     // cout << str <<' ' << idx << ' ' << cur << '\n';
        
    //     if(Node[cur]==NULL) { 
    //         return false;
    //     }

    //     if(idx == str.size()-1) {
    //         return true;
    //     }

    //     return Node[cur]->find(str, idx+1);
    // }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;
        Trie t;
        vector<string> v;
        flag = false;
        for(int i=0; i<N; i++) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        sort(v.begin(), v.end());

        for(string s: v) {
            // cout << s << '\n';
            t.insert(s, 0);
        }
        
        if(flag) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }

    }

    return 0;
}