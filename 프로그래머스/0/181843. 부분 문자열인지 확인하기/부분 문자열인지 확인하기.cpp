#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string my_string, string target)
{
    return my_string.find(target) != string::npos;
}

int main()
{
    cout << solution("banana", "ana") << '\n';
    cout << solution("banana", "wxyz") << '\n';

    return 0;
}