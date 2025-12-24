#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int N;

struct Trie{
    map<string, Trie*> next;

    void insert(const vector<string> words, int words_idx) {
        if(words.size() == words_idx) return;

        string str = words[words_idx];

        Trie *nxt = this->next[str];
        if(nxt == nullptr) {
            nxt = new Trie();
            this->next[str] = nxt;
        } 
        
        nxt->insert(words, words_idx+1);
    }

    void travel(int depth) {
        for(auto p: next) {
            for(int j=0; j<depth; j++) {
                cout << "--";
            }
            cout << p.first << '\n';
            
            p.second->travel(depth+1);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    Trie *root = new Trie();

    for(int i=0; i<N; i++) {
        int cnt;
        cin >> cnt;
        vector<string> words;
        for(int j=0; j<cnt; j++) {
            string input;
            cin >> input;
            words.push_back(input);
        }
        root->insert(words, 0);
    }

    root->travel(0);

    return 0;
}