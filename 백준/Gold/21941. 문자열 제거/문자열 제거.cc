#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int M;
int dp[1005];
unordered_map<string, int> point_map;
vector<string> words;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string input;
    cin >> input >> M;
    input.insert(0, " ");
    int S = input.size()-1;
    for(int i=1; i<=M; i++) {
        string s;
        int p;
        cin >> s >> p;
        words.push_back(s);
        point_map[s] = p;
    }

    for(int i=1; i<=S; i++) {
        for(string word: words) {
            int word_size = word.size();
            string substr = input.substr(i, word_size);
            if(word == substr) {
                dp[i+word_size-1] = max(dp[i+word_size-1], dp[i-1]+point_map[word]);
            }
            else {
                dp[i] = max(dp[i], dp[i-1]+1);
            }
        }
    }

    cout << dp[S];
    return 0;
}