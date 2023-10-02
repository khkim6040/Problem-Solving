#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> inputs;
vector<bool> prime_num_list; //index따라 값이 대응되는게 아니라 0번째 index -> 1, 1->3, 2->5식으로 홀수에 대응됨

void MakePrimeNumList(int m) {
    for(int i=3; i<m; i += 2) {
        bool isPrime = true;
        int n = 3;
        while(i*n < m) {
            if(prime_num_list[i*n/2] == true) {
                prime_num_list[i*n/2] = false;
            }
            n += 2;
        }
    }
}

void FindPrimeNumPair(int n) {
    for(int i=3; i<=n/2; i += 2) {
        if(prime_num_list[i/2] == true && prime_num_list[(n-i)/2] == true) {
            cout << n << " = " << i << " + " << n-i << '\n';
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong." << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    int max_value = 0;
    cin >> n;
    while(n!=0) {
        if(n > max_value) {
            max_value = n;
        }
        inputs.push_back(n);
        cin >> n;
    }
    // 0->1, 1->3, 2->5로 홀수에 대응되게끔 prime_num_list에 true값 넣음
    for(int i=0; i<max_value/2; i++) {
        prime_num_list.push_back(true);
    }
    MakePrimeNumList(max_value);
    
    for(int i=0; i<inputs.size(); i++) {
        FindPrimeNumPair(inputs[i]);
    }
    
    return 0;
}