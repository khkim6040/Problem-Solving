#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define CNT 26
using namespace std;

// 트라이 10000(가능한 단어 길이) * 2(정방향, 역방향) 개

struct Trie{
    Trie* node[CNT];
    bool finish;
    int cnt;
    
    Trie() {
        finish = false;
        cnt = 0;
        for(int i=0; i<CNT; i++) {
            node[i] = NULL;
        }
    }
    
    void insert(string& str, int idx) {
        // cout << str << ' ' << idx << ' ';
        int cur = str[idx] - 'a';
        if(node[cur] == NULL) node[cur] = new Trie();
        node[cur]->cnt++;
        // cout << node[cur]->cnt << '\n';
        if(idx == str.size()-1) {
            finish = true;
            return;
        } else {
            node[cur]->insert(str, idx+1);
        }
    }
    
    int find(string& str, int idx) {
        int cur = str[idx] - 'a';
        if(node[cur] == NULL) return 0;
        if(idx == str.size()-1) return node[cur]->cnt;
        
        return node[cur]->find(str, idx+1);
    }
};

vector<Trie> foward;
vector<Trie> backward;
int N;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    N = words.size();
    
    foward.assign(10001, Trie());
    backward.assign(10001, Trie());
    
    for(string word: words) {
        int len = word.size();
        // foward[len], backword[len] 에 넣음
        Trie* cur = &foward[len];
        cur->cnt++;
        cur->insert(word, 0);
        
        reverse(word.begin(), word.end());
        Trie* bcur = &backward[len];
        bcur->cnt++;
        bcur->insert(word, 0);
        
    }
    
    
    for(string q: queries) {
        int len = q.size();
        if(q[0] == '?' && q[len-1] == '?') {
            // ????
            answer.push_back(foward[len].cnt);
        } else if(q[len-1] != '?') {
            // ??**
            reverse(q.begin(), q.end());
            string s;
            for(char c: q) {
                if(c=='?') break;
                s.push_back(c);
            }
            answer.push_back(backward[len].find(s, 0));
        } else {
            // **??
            string s;
            for(char c: q) {
                if(c=='?') break;
                s.push_back(c);
            }
            answer.push_back(foward[len].find(s, 0));
        }
    }

    
    
    
    return answer;
}