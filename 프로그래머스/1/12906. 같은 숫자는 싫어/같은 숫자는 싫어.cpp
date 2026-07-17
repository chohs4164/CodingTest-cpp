#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    if(arr.empty()) 
        return answer;
    // 일단 첫 요소는 넣기
    answer.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        int current_element = arr[i];
        int previous_element = arr[i - 1];
        if (current_element != previous_element)
        {
            answer.push_back(current_element);
        }
    }
    return answer;
}