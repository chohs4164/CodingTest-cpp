#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion){
        unordered_map<string,int> marathon;

        // 완주자 명단 먼저 넣기
        for(const string& name : completion){
            marathon[name]++;
        }

        // 참가자 돌면서 빼기
        for(const string& name : participant){
            if(marathon[name] == 0)
                return name;
            marathon[name]--;
        }
        return "";
}