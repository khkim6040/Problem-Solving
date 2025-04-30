#include <iostream>
#include <map>
#include <string>

using namespace std;

int N, M;

struct Trie {
    bool finish;
    Trie* Node[26];
    Trie() {
        finish = false;
        for(int i=0; i<26; i++) {
            Node[i] = NULL;
        }
    }

   void insert(string& str, int idx) {
        int cur = str[idx] - 'a';
        if(Node[cur]==NULL) Node[cur] = new Trie();
        if(idx==str.size()-1) {
            finish = true;
            return;
        } else {
            Node[cur]->insert(str, idx+1);
        }
    }

    bool find(string& str, int idx) {
        int cur = str[idx] - 'a';

        
        if(Node[cur]==NULL) { 
            return false;
        }

        if(idx == str.size()-1) {
            return true;
        }

        return Node[cur]->find(str, idx+1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    Trie t;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        t.insert(s, 0);
    }

    int ans = 0;
    for(int i=0; i<M; i++) {
        string s;
        cin >> s;
        if(t.find(s, 0)) {
            ans++;
        } 
    }
    cout << ans;

    return 0;
}