#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(const string &a, const string &b) { return a + b > b + a; }

string solution(vector<int> numbers) {
  string answer = "";
  vector<string> strNumbers;
  for (int i = 0; i < numbers.size(); i++) {
    strNumbers.push_back(to_string(numbers[i]));
  }
  sort(strNumbers.begin(), strNumbers.end(), compare);

  if(strNumbers[0] == "0") return "0";
  for (const string &s : strNumbers) {
    answer += s;
  }
  return answer;
}