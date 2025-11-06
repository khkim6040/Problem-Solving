#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cur;
int op_s;
int op_e;
int len;

int toInt(string s) {
    return 1000*(s[0]-'0') + 100*(s[1]-'0') + 10*(s[3]-'0') + (s[4]-'0');
}

string toStr(int n) {
    string tmp = to_string(n);
    while(tmp.size() < 4) {
        tmp.insert(0, "0");
    }
    string ret;
    ret.resize(5);
    ret[0] = tmp[0];
    ret[1] = tmp[1];
    ret[2] = ':';
    ret[3] = tmp[2];
    ret[4] = tmp[3];
    return ret;
}

void adjust() {
    // see if cur is between op_start and op_end
    if (op_s <= cur && cur <= op_e) {
        cur = op_e;
    }
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    op_s = toInt(op_start);
    op_e = toInt(op_end);
    cur = toInt(pos);
    len = toInt(video_len);
    
    for(string cmd: commands) {
        // cout << cur << ' ';
        adjust();
        if(cmd == "next") {
            cur += 10;
            if(cur%100 >= 60) {
                cur += 40;
            }
            cur = min(cur, len);
        } else {
            cur -= 10;
            if(cur%100 >= 60) {
                cur -= 40;
            }
            cur = max(cur, 0000);
        }
        // cout << cur << '\n';
    } 
    adjust();
    
    return toStr(cur);
}