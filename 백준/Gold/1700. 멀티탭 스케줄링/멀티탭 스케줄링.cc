#include <iostream>
#include <vector>
#include <set>
using namespace std;
int N, K;
vector<int> sequence;
bool activated_device[106];
int activated_size;
int number_of_using[106];

int main()
{
    cin >> N >> K;
    for(int i=0; i<K; i++) {
        int x;
        cin >> x;
        sequence.push_back(x);
        number_of_using[x]++;
    }
    
    int answer = 0;
    for(int i=0; i<K; i++) {
        int device = sequence[i];
        // 플러그 공간 남는경우
        if(activated_device[device] == true) {
            number_of_using[device]--;
            continue;
        }
        if(activated_size < N) {
            activated_device[device] = true;
            activated_size++;
            number_of_using[device]--;
            continue;
        }
        // 이미 플러그에 꽂혀있는 경우
        // 이외, 가장 사용 나중에 하는 device 빼야 함
        int target; // 뽑힐 device
        set<int> check_set;
        // 가장 나중에 사용되는 device 찾기
        for(int j=0; j<K; j++) {
            int next_device = sequence[j];
            // 지금 꽂혀있으면서 앞으로 안쓰이는 device 가장 먼저 뽑음
            if(activated_device[next_device] == true) {
                if(number_of_using[next_device] == 0) {
                    target = next_device;
                    break;
                }
                // 아직 사용 횟수 남았다면 set에 넣음. 중복허용 X
                if(j>i) {
                    check_set.insert(next_device);
                    if(check_set.size() == N) {
                        target = next_device;
                        break;
                    }
                }
            }
        }
        activated_device[target] = false;
        activated_device[device] = true;
        number_of_using[device]--;
        answer++;
    }
    
    cout << answer;
    return 0;
}
