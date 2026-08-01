#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {

  // 내림차순으로 정렬
  sort(citations.begin(), citations.end(), greater<int>());

  int h = 0;
  for (int i = 0; i < citations.size(); i++) {
    if (citations[i] >= i + 1)
      h = i + 1; // 지금까지의 확인한 논문 갯수로 확인
    else
      break;
  }
  return h;
}