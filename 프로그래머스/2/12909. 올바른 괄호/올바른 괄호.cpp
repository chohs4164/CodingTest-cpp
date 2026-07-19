#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        char now = s[i];
        if(now == '('){
            st.push(now);
        }
        else{ // ')'인 경우
            if(!st.empty())
                st.pop();
            else // 꺼내는데 갯수가 안맞으면?
                return false;
        }
        if(i == s.size()-1)
            if(!st.empty())
                return false;
    }
    return true;
}