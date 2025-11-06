#include <string>
#include <vector>

using namespace std;

bool check(int s, int l) {
    int hDif = (l/100 - s/100)*60;
    int mDif = l%100 - s%100;
    return hDif+mDif <= 10;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    int N = schedules.size();
    for(int i=0; i<N; i++) {
        int flag = true;
        int s = schedules[i];
        vector<int> log = timelogs[i];
        int day = startday;
        for(int l: log) {
            if(day == 6 || day == 7) {
                if(day == 7) {
                    day = 1;
                } else {
                    day++;
                }
                continue;
            }
            if(!check(s, l)) {
                flag = false;
                break;
            }
            
            if(day == 7) {
                day = 1;
            } else {
                day++;
            }
        }
        
        if(flag) answer++;
    }
    return answer;
}