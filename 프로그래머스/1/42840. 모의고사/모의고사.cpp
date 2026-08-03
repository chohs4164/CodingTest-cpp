#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> result;
    vector<int> p1 = {1, 2, 3, 4, 5};
    vector<int> p2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int score1 = 0;
    int score2 = 0;
    int score3 = 0;

    for (int i = 0; i < answers.size(); i++) {
        // 1번 수포자 찍는 방식
        if (p1[i % p1.size()] == answers[i])
            score1++;
        if (p2[i % p2.size()] == answers[i])
            score2++;
        if (p3[i % p3.size()] == answers[i])
            score3++;
    }
    int max_score = max({score1, score2, score3});

    if (max_score == score1)
        result.push_back(1);
    if (max_score == score2)
        result.push_back(2);
    if (max_score == score3)
        result.push_back(3);
    return result;
}