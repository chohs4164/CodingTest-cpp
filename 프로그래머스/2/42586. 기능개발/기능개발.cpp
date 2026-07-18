#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> lead_day; // 소요시간
    // 각 걸리는 시간을 계산해서 vector에 저장
    for (int i = 0; i < progresses.size(); i++)
    {
        int remaining_progress = 100 - progresses[i];        // 남은 진도
        int speed = speeds[i];                               // 작업 속도
        int days = (remaining_progress + speed - 1) / speed; // 소요되는 시간
        lead_day.push_back(days);
    }

    int count = 1;
    vector<int> answer;
    int max = lead_day[0];
    for (int i = 1; i < lead_day.size(); i++)
    {
        if (max < lead_day[i])
        {
            max = lead_day[i];
            answer.push_back(count);
            count = 1;
        }
        else
            count++;
    }
    answer.push_back(count);
    return answer;
}