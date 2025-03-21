#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int N;
vector<vector<int>> comb;
vector<int> temp;
map<vector<int>, vector<int>> m; // m[주사위 조합 경우] = 가능한 모든 값들
int _max;
vector<int> temp_ans;

void dfs(int cur, int level) {
    if(level == N/2) {
        comb.push_back(temp);
        return;
    }
    
    for(int i=cur+1; i<N; i++) {
        temp.push_back(i);
        dfs(i, level+1);
        temp.pop_back();
    }
}

void roll(vector<vector<int>> dice, vector<int> _case, int level, int sum) {
    if(level == N/2) {
        m[_case].push_back(sum);
        return;
    }

    vector<int> d = dice[_case[level]];
    for(int i=0; i<6; i++) {
        int temp = sum + d[i];
        roll(dice, _case, level+1, temp);
    }
}

vector<int> get_opponent(vector<int> me) {
    vector<bool> chk(N, true);
    for(auto e: me) {
        chk[e] = false;
    }
    vector<int> res;
    for(int i=0; i<N; i++) {
        if(chk[i]) res.push_back(i);
    }
    return res;
}

void match(vector<int> c) {
    vector<int> me = m[c];
    vector<int> opp = m[(get_opponent(c))];
    
    sort(me.begin(), me.end());
    sort(opp.begin(), opp.end());
    
    int sum = 0;
    for(auto e: me) {  
        int lower = lower_bound(opp.begin(), opp.end(), e) - opp.begin();

        sum += lower;
    }
    if(sum > _max) {
        _max = sum;
        temp_ans = c;
    }

        //     cout << "Case: ";
        // for(auto d: c) {
        //      cout << d << ' ';
        // }
        // cout << '\n';
        // cout << lower << '\n';

}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    N = dice.size();
    
    // 조합
    dfs(-1, 0);
    
//     for(auto vec: comb) {
//         for(auto e: vec) {
//             cout << e << ' ';
//         }
//         cout << '\n';
//     }
    
    // 모든 경우의 수 뽑기
    for(auto _case: comb) {
        roll(dice, _case, 0, 0);
    }
    
//     for(auto iter: m) {
//         cout << iter.first.size() << '\n';
//         cout << iter.second.size() << '\n';
//         for(auto e: iter.second) {
//             cout << e << ' ';
//         }
//         cout << '\n';
//     }
    
    // 조합별로 매치 시키기
    // 이길 확률 구하기
    // 최댓값
    for(auto c: comb) {
        match(c);
    }
    
    for(auto e: temp_ans) {
        answer.push_back(e+1);
    }
    

    return answer;
}
