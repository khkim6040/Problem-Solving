#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

#define ll long long

using namespace std;

struct Node {
    int idx;
    int t;
    
    bool operator< (const Node& other) const {
        if(t==other.t) return idx < other.idx;
        return t < other.t;
    }
};

vector<Node> vec;
int N;
unordered_map<int, int> mapper; // mapper[i] = j -> 없어진 음식을 고려했을 때 i번째 인덱스는 실제로는 j번째 인덱스이다
vector<int> deletedIdx;

int solution(vector<int> food_times, long long k) {
    int answer = -2;
    // food_time 오름차순으로 음식 제거
    // 정렬 {food_time, idx}
    N = food_times.size();
    for(int i=0; i<N; i++) {
        vec.push_back({i, food_times[i]});
        mapper[i] = i;
    }
    sort(vec.begin(), vec.end());
    
    int cnt = N;
    ll elapsed = 0;
    int nums = 1;
    int curMin = 0;
    for(int i=0; i<N; i++) {
        if(i<N-1 && vec[i].t == vec[i+1].t) {
            nums++;
            continue;
        }
        // 해당 음식이 제거되려면 food_time*cnt 초가 지나야 함 cnt--;    
        Node cur = vec[i];
        int idx = cur.idx;
        int t = cur.t - curMin;
        // cout << idx << ' ' << t << ' ' << cnt <<  '\n';
        // if elapsed + food_time*cnt >= k 일 때 해당 음식 사라지기 전에 시간 끝나는 것이므로 세부 계산 시작
        if(elapsed + 1LL*t*cnt > k) {
            // cout << elapsed << '\n';
            // k -= elapsed 
            k -= elapsed;
            // k %= cnt // 이번 음식이 사라지기 전에 시간이 다 되는 것 보장되므로 돌고 나머지를 취하고 그 인덱스를 따라감
            k %= cnt;
            
            // sort(deletedIdx.begin(), deletedIdx.end());
            // k += (lower_bound(deletedIdx.begin(), deletedIdx.end(), k) - deletedIdx.begin()) + 1;
            answer = mapper[0];
            while(answer != mapper[answer]) answer = mapper[answer];
            while(k--) {
                answer = mapper[answer+1];
                while(answer != mapper[answer]) answer = mapper[answer+1];
            }
            break;
            
            // O(N) 말고 O(1) 없나
            // lower_bound 쓰면 O(logN)에 될 듯
            // k + 제외된 음식 idx 오름차순 정렬해 둔 벡터의 크기 - k를 upper_bound 해서 나온 값 = 실제 인덱스
            // k부터 k+delta k 사이에 먹은 음식이 있다면? 그것도 고려해서 추가로 건너띄어야 함. 어떻게?
            // movedK = mapper[k] 하고, movedK의 upper bound 와 delta k 만큼 차이를 더 
            // answer = mapper[k] // while(answer != mapper[answer]) answer = mapper[answer]
        } else {
                    
    // else 
        // elapsed += food_time*cnt
        // mapper[해당 음식 idx] = mapper[idx+1]
            elapsed += 1LL*t*cnt;
            cnt -= nums;
            for(int j=0; j<nums; j++) {
                int idx = vec[i-j].idx;
                mapper[idx] = mapper[idx+1];    
                deletedIdx.push_back(idx);
            }
            curMin = cur.t;
            nums = 1;
        }
    }
    
    


    
    return answer+1;
}