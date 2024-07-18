#include <stdio.h>

int IsCycle;
int Sero, Garo;

char Map[55][55];
char InputMap[55][55];

int Memo[51][51];
int IsVisit[51][51];

int dS[4] = {1, -1, 0, 0};
int dG[4] = {0, 0, 1, -1};

int Max(int num1, int num2) {
    if (num1 > num2)
        return num1;
    else
        return num2;
}

void Input() {
    scanf("%d %d", &Sero, &Garo);

    for (int idx = 0; idx < Sero; idx++)
        scanf("%s", InputMap[idx]);

    for (int idx = 0; idx < Sero; idx++)
        for (int jdx = 0; jdx < Garo; jdx++)
            Map[idx + 1][jdx + 1] = InputMap[idx][jdx];
}

int DFS(int NowS, int NowG) {
    if (Memo[NowS][NowG])
        return Memo[NowS][NowG];

    bool flag = false;
    for (int idx = 0; idx < 4; idx++) {
        int NextS = NowS + (Map[NowS][NowG] - '0') * dS[idx];
        int NextG = NowG + (Map[NowS][NowG] - '0') * dG[idx];

        if (NextS >= 1 && NextG >= 1 && NextS <= Sero && NextG <= Garo) {
            if ('1' <= Map[NextS][NextG] && Map[NextS][NextG] <= '9') {
                flag = true;
                if (IsVisit[NextS][NextG] == 1)
                    IsCycle = 1;
                else {
                    IsVisit[NextS][NextG] = 1;
                    Memo[NowS][NowG] = Max(Memo[NowS][NowG], DFS(NextS, NextG) + 1);
                    IsVisit[NextS][NextG] = 0;
                }
            }
        }
    }

    if (!flag) Memo[NowS][NowG] = 1;
    return Memo[NowS][NowG];
}

void Solve() {
    Input();

    IsVisit[1][1] = 1;
    int Answer = DFS(1, 1);

    if (IsCycle == 1)
        printf("-1\n");
    else
        printf("%d\n", Answer);
}

int main(void) {
    Solve();
    return 0;
}