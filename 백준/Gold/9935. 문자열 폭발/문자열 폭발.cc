#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>

#define pii pair<int, int>


using namespace std;

string a, b;

unordered_map<char, int> seq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    int bs = b.size();
    for(int i=0; i<bs; i++) {
        // if seq[i] 쓰려고 1 더해서 저장함. 안그러면 0이 겹침
        seq[b[i]] = i+1;
    }
    // 순방향으로 a 탐색
    // 스택에 char 넣으면서 문자열 만들기
    // b 완성되면 그만큼 스택에서 지움
    // 지워지고 이미 들어간 이전 값들 몇개 빼면서 혹시 이전 값과 이후 값이 이어졌을 때 b가 만들어지는 지 확인해야 함
        // b는 문자가 하나씩밖에 들어가지 않으므로 주어진 문자열에 값이 있는지 없는지 

    string cur = "";
    int idx = 0;
    deque<char> aa;
    for(char c: a) {
        aa.push_back(c);
    }
    deque<char> s;
    while(!aa.empty()) {
        char c = aa.front();
        // cout << c << ' ';
        aa.pop_front();
        if(c == b[idx]) {
            cur.push_back(c);
            idx++;
            if(idx == bs) {
                // 완성
                // 스택의 이전 값들도 보기
                // int cur_idx = 44;
                // stack<char> ss;
                // while(!s.empty() && cur_idx>0) {
                //     char e = s.back();

                //     if(!seq[e]) break;
                    
                //     s.pop_back();
                //     ss.push(e);


                //     if(cur_idx == 44) {
                //         cur_idx = seq[e]-1;
                //     } else if(b[cur_idx] != seq[e]-1) {
                //         break;
                //     }
                //     cur_idx--;
                // }

                // if(cur_idx != 0) {
                //     // ss 넣기
                //     while(!ss.empty()) {
                //         s.push_back(ss.top());
                //         ss.pop();
                //     }
                // } else {
                //     // idx 조정 및 cur string에 넣기
                //     idx = ss.size();
                //     while(!ss.empty()) {
                //         cur.push_back(ss.top());
                //         ss.pop();
                //     }
                // }

                idx = 0;
                cur = "";
                if(s.empty()) continue;
                char e = s.back();
                if(seq[e]) {
                    // deque<char> tmp = s;
                    // while(!tmp.empty()) {
                    //     cout << tmp.front();
                    //     tmp.pop_front();
                    // }
                    // cout << '\n';
                    int cnt = seq[e];
                    while(!s.empty() && cnt-- && seq[s.back()]) {
                        aa.push_front(s.back());
                        s.pop_back();
                    }
                    
                }
            } 
        } else {
            bool flag = c==b[0];
            if(!flag) {
                cur.push_back(c);
            } 

            for(char cc: cur) {
                s.push_back(cc);
            }
            idx = 0;
            cur = "";

            if(flag) {
                cur.push_back(c);
                idx++;
            }

        }
    }

    for(char c: cur) {
        s.push_back(c);
    }

    if(s.size() == 0) {
        cout << "FRULA";
    } else {
        while(!s.empty()) {
            cout << s.front();
            s.pop_front();
        }
    }

    return 0;
}