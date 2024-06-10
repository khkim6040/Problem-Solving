#include <iostream>
using namespace std;

int r_side[] = {0, 1, 2, 1};
int c_side[] = {1, 0, 1, 2};

int r_edge[] = {0, 2, 2, 0};
int c_edge[] = {0, 0, 2, 2};

class Cube {
   private:
    char up[3][3];
    char front[3][3];
    char right[3][3];
    char back[3][3];
    char left[3][3];
    char down[3][3];

   public:
    Cube() {
        fill_n(&up[0][0], 9, 'w');
        fill_n(&front[0][0], 9, 'r');
        fill_n(&right[0][0], 9, 'b');
        fill_n(&back[0][0], 9, 'o');
        fill_n(&left[0][0], 9, 'g');
        fill_n(&down[0][0], 9, 'y');
    }

    void rotateU(int n) {
        // 면 시계방향 회전
        char tmp_side;
        char tmp_edge;
        for (int i = 0; i < n; i++) {
            tmp_side = up[r_side[0]][c_side[0]];
            tmp_edge = up[r_edge[0]][c_edge[0]];
            for (int j = 0; j < 3; j++) {
                up[r_side[j]][c_side[j]] = up[r_side[j + 1]][c_side[j + 1]];
                up[r_edge[j]][c_edge[j]] = up[r_edge[j + 1]][c_edge[j + 1]];
            }
            up[r_side[3]][c_side[3]] = tmp_side;
            up[r_edge[3]][c_edge[3]] = tmp_edge;
            // 인접한 4개 면의 행 시계방향 회전
            char tmp_row[3];
            tmp_row[0] = front[0][0];
            tmp_row[1] = front[0][1];
            tmp_row[2] = front[0][2];
            front[0][0] = right[0][0];
            front[0][1] = right[0][1];
            front[0][2] = right[0][2];
            right[0][0] = back[0][0];
            right[0][1] = back[0][1];
            right[0][2] = back[0][2];
            back[0][0] = left[0][0];
            back[0][1] = left[0][1];
            back[0][2] = left[0][2];
            left[0][0] = tmp_row[0];
            left[0][1] = tmp_row[1];
            left[0][2] = tmp_row[2];
        }
    }

    void rotateF(int n) {
        char tmp_side;
        char tmp_edge;
        for (int i = 0; i < n; i++) {
            tmp_side = front[r_side[0]][c_side[0]];
            tmp_edge = front[r_edge[0]][c_edge[0]];
            for (int j = 0; j < 3; j++) {
                front[r_side[j]][c_side[j]] = front[r_side[j + 1]][c_side[j + 1]];
                front[r_edge[j]][c_edge[j]] = front[r_edge[j + 1]][c_edge[j + 1]];
            }
            front[r_side[3]][c_side[3]] = tmp_side;
            front[r_edge[3]][c_edge[3]] = tmp_edge;
            char tmp_row[3];
            tmp_row[0] = down[0][0];
            tmp_row[1] = down[0][1];
            tmp_row[2] = down[0][2];
            down[0][0] = right[2][0];
            down[0][1] = right[1][0];
            down[0][2] = right[0][0];
            right[2][0] = up[2][2];
            right[1][0] = up[2][1];
            right[0][0] = up[2][0];
            up[2][2] = left[0][2];
            up[2][1] = left[1][2];
            up[2][0] = left[2][2];
            left[0][2] = tmp_row[0];
            left[1][2] = tmp_row[1];
            left[2][2] = tmp_row[2];
        }
    }

    void rotateR(int n) {
        char tmp_side;
        char tmp_edge;
        for (int i = 0; i < n; i++) {
            tmp_side = right[r_side[0]][c_side[0]];
            tmp_edge = right[r_edge[0]][c_edge[0]];
            for (int j = 0; j < 3; j++) {
                right[r_side[j]][c_side[j]] = right[r_side[j + 1]][c_side[j + 1]];
                right[r_edge[j]][c_edge[j]] = right[r_edge[j + 1]][c_edge[j + 1]];
            }
            right[r_side[3]][c_side[3]] = tmp_side;
            right[r_edge[3]][c_edge[3]] = tmp_edge;
            char tmp_row[3];
            tmp_row[0] = down[0][2];
            tmp_row[1] = down[1][2];
            tmp_row[2] = down[2][2];
            down[0][2] = back[2][0];
            down[1][2] = back[1][0];
            down[2][2] = back[0][0];
            back[2][0] = up[0][2];
            back[1][0] = up[1][2];
            back[0][0] = up[2][2];
            up[0][2] = front[0][2];
            up[1][2] = front[1][2];
            up[2][2] = front[2][2];
            front[0][2] = tmp_row[0];
            front[1][2] = tmp_row[1];
            front[2][2] = tmp_row[2];
        }
    }

    void rotateB(int n) {
        char tmp_side;
        char tmp_edge;
        for (int i = 0; i < n; i++) {
            tmp_side = back[r_side[0]][c_side[0]];
            tmp_edge = back[r_edge[0]][c_edge[0]];
            for (int j = 0; j < 3; j++) {
                back[r_side[j]][c_side[j]] = back[r_side[j + 1]][c_side[j + 1]];
                back[r_edge[j]][c_edge[j]] = back[r_edge[j + 1]][c_edge[j + 1]];
            }
            back[r_side[3]][c_side[3]] = tmp_side;
            back[r_edge[3]][c_edge[3]] = tmp_edge;
            char tmp_row[3];
            tmp_row[0] = down[2][2];
            tmp_row[1] = down[2][1];
            tmp_row[2] = down[2][0];
            down[2][2] = left[2][0];
            down[2][1] = left[1][0];
            down[2][0] = left[0][0];
            left[2][0] = up[0][0];
            left[1][0] = up[0][1];
            left[0][0] = up[0][2];
            up[0][0] = right[0][2];
            up[0][1] = right[1][2];
            up[0][2] = right[2][2];
            right[0][2] = tmp_row[0];
            right[1][2] = tmp_row[1];
            right[2][2] = tmp_row[2];
        }
    }

    void rotateL(int n) {
        char tmp_side;
        char tmp_edge;
        for (int i = 0; i < n; i++) {
            tmp_side = left[r_side[0]][c_side[0]];
            tmp_edge = left[r_edge[0]][c_edge[0]];
            for (int j = 0; j < 3; j++) {
                left[r_side[j]][c_side[j]] = left[r_side[j + 1]][c_side[j + 1]];
                left[r_edge[j]][c_edge[j]] = left[r_edge[j + 1]][c_edge[j + 1]];
            }
            left[r_side[3]][c_side[3]] = tmp_side;
            left[r_edge[3]][c_edge[3]] = tmp_edge;
            char tmp_row[3];
            tmp_row[0] = down[2][0];
            tmp_row[1] = down[1][0];
            tmp_row[2] = down[0][0];
            down[2][0] = front[2][0];
            down[1][0] = front[1][0];
            down[0][0] = front[0][0];
            front[2][0] = up[2][0];
            front[1][0] = up[1][0];
            front[0][0] = up[0][0];
            up[2][0] = back[0][2];
            up[1][0] = back[1][2];
            up[0][0] = back[2][2];
            back[0][2] = tmp_row[0];
            back[1][2] = tmp_row[1];
            back[2][2] = tmp_row[2];
        }
    }

    void rotateD(int n) {
        char tmp_side;
        char tmp_edge;
        for (int i = 0; i < n; i++) {
            tmp_side = down[r_side[0]][c_side[0]];
            tmp_edge = down[r_edge[0]][c_edge[0]];
            for (int j = 0; j < 3; j++) {
                down[r_side[j]][c_side[j]] = down[r_side[j + 1]][c_side[j + 1]];
                down[r_edge[j]][c_edge[j]] = down[r_edge[j + 1]][c_edge[j + 1]];
            }
            down[r_side[3]][c_side[3]] = tmp_side;
            down[r_edge[3]][c_edge[3]] = tmp_edge;
            char tmp_row[3];
            tmp_row[0] = front[2][0];
            tmp_row[1] = front[2][1];
            tmp_row[2] = front[2][2];
            front[2][0] = left[2][0];
            front[2][1] = left[2][1];
            front[2][2] = left[2][2];
            left[2][0] = back[2][0];
            left[2][1] = back[2][1];
            left[2][2] = back[2][2];
            back[2][0] = right[2][0];
            back[2][1] = right[2][1];
            back[2][2] = right[2][2];
            right[2][0] = tmp_row[0];
            right[2][1] = tmp_row[1];
            right[2][2] = tmp_row[2];
        }
    }

    void print() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << up[i][j];
            }
            cout << '\n';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        Cube cube;
        while (N--) {
            char c, d;
            cin >> c >> d;
            int n = d == '+' ? 1 : 3;
            if (c == 'U') {
                cube.rotateU(n);
            } else if (c == 'F') {
                cube.rotateF(n);
            } else if (c == 'R') {
                cube.rotateR(n);
            } else if (c == 'B') {
                cube.rotateB(n);
            } else if (c == 'L') {
                cube.rotateL(n);
            } else if (c == 'D') {
                cube.rotateD(n);
            }
        }
        cube.print();
    }

    return 0;
}