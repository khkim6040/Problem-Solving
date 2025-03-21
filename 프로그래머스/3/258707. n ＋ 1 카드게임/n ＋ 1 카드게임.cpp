#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool hands[1005];
int answer = 0;
vector<int> _cards;
int _coin;
int N;

void dfs(int pair) {
    int idx = N/3 + 2*(pair+1);
    if(idx > N) {
        answer = N/3+1;
        return;
    }
    cout << idx << '\n';
    // vector<int> temp = _cards[N/3+1:idx];
    bool temp_hands[1005] = {0, };
    int cur_pair = pair;
    for(int i=N/3; i<idx; i++) {
        int e = _cards[i];
        temp_hands[e] = true;
    }
    
    // 원래 들고있던 패와 매치
    for(int i=N/3; i<idx; i++) {
        int e = _cards[i];
        if(hands[e]) continue;
        
        if(hands[N+1-e] && _coin>0) {
            hands[e] = true;
            cur_pair++;
            _coin--;
        } 
    }
    // 원래 들고있던 것과 매치되는게 있다면 바로 다음거 고려하도록
    if(cur_pair > pair) {
        answer = max(answer, cur_pair);
        if(cur_pair >= N/3) {
            answer = N/3+1;
            return;
        }
        dfs(cur_pair);
    } else {
         // 뽑은 것들 사이에서 매치
        for(int i=N/3; i<idx; i++) {
            int e = _cards[i];
            if(hands[e]) continue;

            if(temp_hands[N+1-e] && _coin>1) {
                hands[e] = true;
                hands[N+1-e] = true;
                cur_pair++;
                _coin -= 2;
                dfs(cur_pair);
            }
        }

        if(cur_pair == pair || cur_pair >= N/3) {
            answer = max(answer, cur_pair+1);
            answer = min(answer, N/3+1);
            return;
        } else {
            dfs(cur_pair);
        }   
    }
}

int solution(int coin, vector<int> cards) {
    _cards = cards;
    _coin = coin;
    N = cards.size();
    int pair = 0;
    for(int i=0; i<N/3; i++) {
        int x = cards[i];
        hands[x] = true;
        if(hands[N+1-x]) {
            pair++;
        }
    }
    cout << pair << '\n';
    
    dfs(pair);
    
    
    return answer;
}