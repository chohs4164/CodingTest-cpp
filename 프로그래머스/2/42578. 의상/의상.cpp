#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes){
    int count = 1;
    unordered_map<string,int> cloth_map;

    for(vector<string> clothAndType : clothes){
        cloth_map[clothAndType[1]]++;
    }

    for(const auto& pair : cloth_map){
        count *= (pair.second+1);
    }
    return count-1;
}