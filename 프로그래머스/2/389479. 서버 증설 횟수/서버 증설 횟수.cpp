#include <string>
#include <vector>
#include <iostream>

using namespace std;

int endCnt[30]; // endCnt[i] = i시간대에 내려갈 서버 수
int serverCnt;


int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int size = players.size();
    for(int i=0; i<size; i++) {
        int p = players[i];
        serverCnt -= endCnt[i];
        if(p/m > serverCnt) {
            // cout << i << '\n';
            int needToSet = p/m - serverCnt;
            answer += needToSet;
            serverCnt += needToSet;
            endCnt[i+k] = needToSet;
        }
    }
    return answer;
}