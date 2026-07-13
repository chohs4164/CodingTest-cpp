#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> phoneketmon;
    // 각 포켓몬과 그 갯수 저장
    for (int mon : nums){
        phoneketmon[mon]++;
    } 

    return min(nums.size() / 2, phoneketmon.size());
} 