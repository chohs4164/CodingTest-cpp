#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack<int> st; // 주식을 산 시점을 계산
    for (int i = 0; i < prices.size(); i++)
    {
        while (!st.empty() && prices[st.top()] > prices[i])
        { // 이전보다 떨어졌다면
            int lead_time = st.top();
            st.pop();
            answer[lead_time] = i - lead_time;
        }
        // 현재 시간 계산
        st.push(i);
    }
    // 장 마감때까지 가격이 떨어지지 않아서 스택을 비워버리며 소요되었던 시간 저장
    while (!st.empty())
    {
        int lead_time = st.top(); // 소요시간 계산
        st.pop();
        answer[lead_time] = (prices.size() - 1 - lead_time);
    }
    return answer;
}