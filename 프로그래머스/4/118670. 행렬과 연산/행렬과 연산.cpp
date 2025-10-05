#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

vector<deque<int>> dMiddle;
deque<int> dLeft;
deque<int> dRight;

int R, C;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    R = rc.size();
    C = rc[0].size();
    
    for(int i=0; i<R; i++) {
        deque<int> temp;
        for(int j=0; j<C; j++) {
            int e = rc[i][j];
            if(j==0) {
                dLeft.push_back(e);   
            } else if(j==C-1) {
                dRight.push_back(e);   
            } else {
                temp.push_back(e);
            }
        }
        dMiddle.push_back(temp);
    }
    
    // cout << dLeft.front() << ' ' <<dLeft.back() << '\n';
    // cout << dRight.front() << ' ' <<dRight.back() << '\n';
    // cout << dMiddle.front().front() << ' ' <<dMiddle.front().back() << '\n';
    // cout << dMiddle.back().front() << ' ' <<dMiddle.back().back() << '\n';
    
    int topIdx = 0; // dMiddle
    
    int cnt = 1;
    string prev = operations[0];
    int size = operations.size();
    for(int i=1; i<size; i++) {
        string cur = operations[i];
        if(cur==prev) {
            cnt++;
        } else {
            if(prev == "ShiftRow") {
                cnt %= R;            
                // middle은 계산 안 함 O(N) 걸림
                topIdx += (R-cnt);
                topIdx %= R;
                while(cnt--) {
                    dLeft.push_front(dLeft.back());
                    dLeft.pop_back();

                    dRight.push_front(dRight.back());
                    dRight.pop_back();
                }
            } else {
                cnt %= (2*(R-2) + 2*(C-2) + 4);
                while(cnt--) {
                    int e1 = dLeft.front();
                    dLeft.pop_front();
                    
                    dMiddle[topIdx].push_front(e1);
                    int e2 = dMiddle[topIdx].back();
                    dMiddle[topIdx].pop_back();

                    dRight.push_front(e2);
                    int e3 = dRight.back();
                    dRight.pop_back();

                    dMiddle[(topIdx+R-1)%R].push_back(e3);
                    int e4 = dMiddle[(topIdx+R-1)%R].front();
                    dMiddle[(topIdx+R-1)%R].pop_front();

                    dLeft.push_back(e4);
                }

            }
            cnt = 1;
        }
        prev = cur;
    }
    
    if(prev == "ShiftRow") {
        cnt %= R;
        // middle은 계산 안 함 O(N) 걸림
        topIdx += (R-cnt);
        topIdx %= R;
        while(cnt--) {
            dLeft.push_front(dLeft.back());
            dLeft.pop_back();

            dRight.push_front(dRight.back());
            dRight.pop_back();
        }
    } else {
        cnt %= (2*(R-2) + 2*(C-2) + 4);
        while(cnt--) {
            int e1 = dLeft.front();
            dLeft.pop_front();

            dMiddle[topIdx].push_front(e1);
            int e2 = dMiddle[topIdx].back();
            dMiddle[topIdx].pop_back();

            dRight.push_front(e2);
            int e3 = dRight.back();
            dRight.pop_back();

            dMiddle[(topIdx+R-1)%R].push_back(e3);
            int e4 = dMiddle[(topIdx+R-1)%R].front();
            dMiddle[(topIdx+R-1)%R].pop_front();

            dLeft.push_back(e4);
        }
    }
    
    // cout << topIdx << '\n';
    
    vector<vector<int>> answer;
    answer.assign(R, vector<int>(C));
    
    for(int i=0; i<R; i++) {
        deque<int> mid = dMiddle[(topIdx+i)%R];
        for(int j=0; j<C; j++) {
            if (j==0) {
                answer[i][j] = dLeft.front();
                dLeft.pop_front();
            } else if(j==C-1) {
                answer[i][j] = dRight.front();
                dRight.pop_front();
            } else {
                answer[i][j] = mid.front();
                mid.pop_front();
            }
        }
    }
    
    
    
    return answer;
}