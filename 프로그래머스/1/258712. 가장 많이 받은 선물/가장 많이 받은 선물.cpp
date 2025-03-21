#include <string>
#include <vector>
#include <map>
#include <iostream>

#define _NULL 2111111111
using namespace std;

int history[55][55];
int present_index[55];
int present[55];

int solution(vector<string> friends, vector<string> gifts) {
    
    fill_n(&history[0][0], 55*55, _NULL);
    
    int N = friends.size();
    map<string, int> ntoi;
    map<int, string> iton;
    
    for(int i=0; i<N; i++) {
        ntoi.insert({friends[i], i});
        iton.insert({i, friends[i]});
        // cout << m[friends[i]] <<' ';
    }
    int size = gifts.size();
    for(int i=0; i<size; i++) {
        string gift = gifts[i];
        string froms = "";
        string tos = "";
        
        bool flag = false;
        for(char c: gift) {
            if(c == ' ') {
                flag = true;
                continue;
            }
            
            if(!flag) {
                froms.push_back(c);
            }
            else {
                tos.push_back(c);        
            }
        }
        cout << froms << ' ' << tos << '\n';
        
        int from = ntoi[froms];
        int to = ntoi[tos];
        
        
        present_index[from]++;
        present_index[to]--;
        
        if (from < to) {
            if (history[from][to] == _NULL) {
                history[from][to] = 1;
            } else {
                history[from][to]++;
            }
        } else {
            if (history[to][from] == _NULL) {
                history[to][from] = -1;
            } else {
                history[to][from]--;
            }
        }
    }
    
    int answer = 0;
    
    for(int i=0; i<N; i++) {
        cout << "present index: " << i << ' ' << present_index[i] << '\n';
        for(int j=i+1; j<N; j++) {
            cout << i << ' ' << j << ' ' << history[i][j]  << '\n';
            
            if (history[i][j] != _NULL && history[i][j] != 0) {
                if(history[i][j] > 0) {
                    present[i]++;
                } else if(history[i][j] < 0) {
                    present[j]++;
                }    
            }
            else {
                if (present_index[i] > present_index[j]) {
                    present[i]++;
                } else if (present_index[i] < present_index[j]) {
                    present[j]++;
                }
            }
        }
        
        cout << i << ' ' << present[i] << '\n';
        
        answer = max(answer, present[i]);
    }
    
    return answer;
}