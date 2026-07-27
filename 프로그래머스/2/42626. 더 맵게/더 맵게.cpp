#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    int answer = 0;

    while (pq.top() < K)
    {
        // 만약 K를 넘을 수 없다면
        if (pq.size() < 2)
            return -1;

        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int twisted = first + (second * 2);
        pq.push(twisted);

        answer++;
    }
    return answer;
}