#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> answer;
  for (int i = 0; i < commands.size(); i++) {
    int start = commands[i][0] - 1;
    int end = commands[i][1];
    int k = commands[i][2] - 1;
    // 숫자 자르고
    vector<int> subst(array.begin() + start, array.begin() + end);

    // 오름차순으로 정렬
    sort(subst.begin(), subst.end());

    answer.push_back(subst[k]);
  }
  return answer;
}