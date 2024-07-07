#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

vector<string> vec;
vector<bool> mark;
vector<string> finder = {"c", "j", "n", "m", "t", "s", "l", "d", "qu"};
vector<char> bowl = {'a', 'e', 'i', 'o', 'u', 'h'};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s;
    getline(cin, s);
    mark.resize(s.size());
    string ss;
    int s_size = s.size();
    for (int i = 0; i < s_size; i++) {
        char c = s[i];
        if (c == ' ' || c == '-') {
            vec.push_back(ss);
            ss = "";
        } else if ((c == '\'') && (find(bowl.begin(), bowl.end(), s[i + 1]) != bowl.end())) {
            vec.push_back(ss);
            ss = "";
            mark[vec.size() - 1] = true;

        } else {
            ss += c;
        }
    }
    vec.push_back(ss);

    // cout << vec.size();
    int size = vec.size();
    int ans = vec.size();
    for (int i = 0; i < size; i++) {
        // cout << vec[i] << ' ';
        if (mark[i] && find(finder.begin(), finder.end(), vec[i]) == finder.end()) {
            // cout << vec[i] << ' ';
            ans--;
        }
    }

    cout << ans;

    return 0;
}