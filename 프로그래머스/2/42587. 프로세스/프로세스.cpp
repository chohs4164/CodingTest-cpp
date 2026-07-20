#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(make_pair(priorities[i], i));
        pq.push(priorities[i]);
    }
    int count = 0;
    while ((!q.empty()))
    {
        pair<int, int> element = q.front();
        if (element.first < pq.top())
        {
            q.pop();
            q.push(element);
        }
        if (element.first == pq.top())
        {
            count++;
            if (element.second == location)
                return count;
            else
            {
                q.pop();
                pq.pop();
            }
        }
    }
    return 0;
}