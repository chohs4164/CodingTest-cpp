#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    // 장르별 총 재생 횟수 저장
    unordered_map<string, int> genres_total_count;

    // 장르, 재생 횟수, 고유 번호 저장
    unordered_map<string, vector<pair<int, int>>> genre_songs;

    for (int i = 0; i < genres.size(); i++)
    {
        genres_total_count[genres[i]] += plays[i];
        genre_songs[genres[i]].push_back({plays[i], i});
    }

    int best_genre_count = genres_total_count[genres[0]];
    string best_genre = genres[0];

    vector<pair<string, int>> genre_ranking(genres_total_count.begin(), genres_total_count.end());

    // 재생 횟수 순서대로 정렬
    sort(genre_ranking.begin(), genre_ranking.end(), [](const pair<string, int> &a, const pair<string, int> &b)
         { return a.second > b.second; });

    vector<int> answer;
    int index = 0;
    for (const auto &genre_info : genre_ranking)
    {
        string current_genre = genre_info.first;

        auto &songs = genre_songs[current_genre];
        sort(songs.begin(), songs.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
            // 만약 재생 횟수가 같다면 고유 번호가 낮은거 부터
            if(a.first==b.first)
                return a.second < b.second;
            return a.first > b.first; });

        for (int i = 0; i < 2 && i < songs.size() ; i++)
        {
            answer.push_back(songs[i].second);
        }
    }
    return answer;
}