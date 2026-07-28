#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Job
{
    int request_time; // 작업의 요청시각
    int duration;     // 작업의 소요시간
    int id;           // 작업의 번호
};

struct Compare
{
    bool operator()(const Job &a, const Job &b)
    {
        // 작업의 소요시각이 짧은 순
        if (a.duration != b.duration)
            return a.duration > b.duration;

        // 작업의 요청시각이 빠른 순
        if (a.request_time != b.request_time)
            return a.request_time > b.request_time;
        return a.id > b.id;
    }
};

int solution(vector<vector<int>> jobs)
{
    sort(jobs.begin(), jobs.end());

    priority_queue<Job, vector<Job>, Compare> pq;

    int total_time = 0;   // 총 시간 누적
    int current_time = 0; // 현재 시각
    int job_index = 0;    // jobs 배열 탐색을 위한 인덱스
    int count = 0;        // 완료된 작업의 수
    int n = jobs.size();

    while (count < n)
    {
        // 현재 시각 보다 이전에 도착한 작업들은 모두 pq에 넣어서 순서대로 처리
        while (job_index < n && jobs[job_index][0] <= current_time)
        {
            pq.push(Job{jobs[job_index][0], jobs[job_index][1], job_index});
            job_index++;
        }

        // 실행할 작업이 대기하고 있으면
        if (!pq.empty())
        {
            // 하나 꺼내서 시간에 추가
            Job top_job = pq.top();
            pq.pop();
            current_time += top_job.duration;
            total_time += (current_time - top_job.request_time);
            count++;
        }
        else // 대기하고 있는 작업이 없는데 처리할 작업이 남았다면
        {
            current_time = jobs[job_index][0]; // 다음 작업의 요청 시각으로 갱신
        }
    }
    return total_time / n;
}