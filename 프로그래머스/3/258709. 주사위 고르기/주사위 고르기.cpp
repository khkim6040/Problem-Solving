#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


// 절반을 선택할때 선택한 리스트들
vector<vector<int>> ListA;
vector<vector<int>> ListB;

vector<int> SumA;
vector<int> SumB;

int sortnum = 0;
int choice = 0;


void MakeList(int now,int count, vector<int>A, vector<int>B) {// now 현재위치 , count 고를 수 

    int tempA = A.size();
    int tempB = B.size();


    if (tempA == count && tempB == count) {
        ListA.push_back(A);
        ListB.push_back(B);
        return;
    }

    if (tempA == count) {
        B.push_back(now);
        MakeList(now + 1, count, A, B);
    }
    else if (tempB == count) {
        A.push_back(now);
        MakeList(now + 1, count, A, B);
    }
    else {
        A.push_back(now);
        MakeList(now + 1, count, A, B);
        A.pop_back();

        B.push_back(now);
        MakeList(now + 1, count, A, B);
        B.pop_back();

    }
}

void sumCal(int count, int maxSum, vector<int> List, vector<vector<int>> dice) {

    if (count == 0) {

        if (sortnum == 0) {
            SumA.push_back(maxSum);
        }
        else {
            SumB.push_back(maxSum);
        }

        return;
    }


    for (int i = 0; i < dice[List[count-1]].size(); i++) {
        sumCal(count - 1, maxSum + dice[List[count-1]][i], List, dice);
    }
}


// 몇번째 다이스에서 숫자 머를 뽑았는지 해서 모든 합을 구해야할듯
vector<int> diceCal(vector<vector<int>> dice) { // 현재 골라놓은 다이스리스트들

    int Maxvictory = 0;
    vector<int>MaxList; // 가장 합이 

    for (int i = 0; i < ListA.size(); i++) {

        sortnum = 0;
        sumCal(choice, 0, ListA[i], dice);

        sortnum = 1;
        sumCal(choice, 0, ListB[i], dice);


        // 서로의 합이 나온 부분

        int maxTemp = 0;



        for (int j = 0; j < SumA.size(); j++) {

            for (int k = 0; k < SumB.size(); k++) {
                if (SumA[j] > SumB[k]) {
                    maxTemp += 1;
                }
                
            }
        }
        if (maxTemp > Maxvictory) { // 승리할 확률 최신화
            Maxvictory = maxTemp;

            sort(ListA[i].begin(), ListA[i].end());
            MaxList= ListA[i];
        }

        SumA.clear();
        SumB.clear();
    }

    return MaxList;

}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    vector<int> A, B;


    int n = dice.size();
    choice = n / 2;

    MakeList(0, choice, A, B); // 시작 위치 / 선택할 주사위 수 


    answer=diceCal(dice);

    for (int i = 0; i < answer.size(); i++) {
        answer[i] += 1;
    }


    return answer;
}
