#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
  vector<int> max_size(5); // 두 변 중 긴 쪽
  vector<int> min_size(5); // 두 변 중 짧은 쪽

  for (int i = 0; i < sizes.size(); i++) {
    int size1 = sizes[i][0];
    int size2 = sizes[i][1];

    if (size1 > size2) {
      max_size.push_back(size1);
      min_size.push_back(size2);
    } else {
      max_size.push_back(size2);
      min_size.push_back(size1);
    }
  }
  sort(max_size.begin(), max_size.end(), greater<int>());
  sort(min_size.begin(), min_size.end(), greater<int>());
  return max_size[0] * min_size[0];
}