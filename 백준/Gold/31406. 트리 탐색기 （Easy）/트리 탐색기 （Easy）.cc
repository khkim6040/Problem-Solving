#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int number;
    bool is_toggled;
    bool is_seen;
};
int N, Q;

vector<vector<int>> graph;
int cur_pointer;

vector<Node> index_list;
int index = 1;
int initial_cur_point;
int mapper[2005];  // map number to index

void make_index_list(int num) {
    mapper[num] = index;
    index_list[index] = {num, false, false};
    index++;
    for (auto chld : graph[num]) {
        make_index_list(chld);
    }
}

void toggle_to_false() {
    index_list[cur_pointer].is_toggled = false;
    stack<int> s;
    s.push(index_list[cur_pointer].number);
    // 현재 노드의 chld들 안보이게 함
    while (!s.empty()) {
        int num = s.top();
        s.pop();
        for (auto chld : graph[num]) {
            index_list[mapper[chld]].is_seen = false;  // 이것만 의미 있을수도? 어차피 그래프는 탐색용도로만 쓰임
            s.push(chld);
        }
    }
}

void toggle_to_true() {
    index_list[cur_pointer].is_toggled = true;
    queue<int> q;
    q.push(index_list[cur_pointer].number);
    // 자신이 toggle 되어있다면 인접한 자식들의 is_seen = true로
    while (!q.empty()) {
        int number = q.front();
        q.pop();
        if (!index_list[mapper[number]].is_toggled)
            continue;
        for (auto chld : graph[number]) {
            index_list[mapper[chld]].is_seen = true;
            q.push(chld);
        }
    }
}

void move_pointer(int &k) {
    int temp_pointer = cur_pointer;
    if (k > 0) {
        while (k > 0 && temp_pointer < N) {
            temp_pointer++;
            if (index_list[temp_pointer].is_seen) {
                cur_pointer = temp_pointer;
                k--;
            }
            if (temp_pointer == N) {
                break;
            }
        }

    } else {
        while (k < 0 && temp_pointer > initial_cur_point) {
            temp_pointer--;
            if (index_list[temp_pointer].is_seen) {
                cur_pointer = temp_pointer;
                k++;
            }
            if (temp_pointer == initial_cur_point) {
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    graph.assign(N + 1, vector<int>());
    index_list.assign(N + 1, Node());
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        while (num--) {
            int j;
            cin >> j;
            // Directed graph
            graph[i].push_back(j);
        }
        // cout << '\n';
    }
    // Start from 1st node
    make_index_list(1);

    // 1st node의 chld들은 보여야 함
    for (auto chld : graph[1]) {
        index_list[mapper[chld]].is_seen = true;
    }
    initial_cur_point = mapper[graph[1][0]];  // Folder 1의 첫 번째 chld에서 시작
    cur_pointer = initial_cur_point;
    while (Q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "toggle") {
            if (index_list[cur_pointer].is_toggled) {
                toggle_to_false();
            } else {
                toggle_to_true();
            }
        } else if (cmd == "move") {
            int k;
            cin >> k;
            move_pointer(k);
            cout << index_list[cur_pointer].number << '\n';
        }
    }
    return 0;
}