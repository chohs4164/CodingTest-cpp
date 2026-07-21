#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int time = 0;
    int index = 0;         // 다음에 진입할 트럭의 인덱스
    int bridge_weight = 0; // 현재 다리 위 무게
    queue<int> bridge;     // 다리

    // 다리 길이만큼 0으로 채우고
    for (int i = 0; i < bridge_length; i++)
    {
        bridge.push(0);
    }

    // 트럭이 다 지나갈때까지 돌린다.
    while (index < truck_weights.size())
    {
        time++;

        // 한 칸 앞으로 이동
        bridge_weight -= bridge.front(); // 현재 다리 위 무게 갱신
        bridge.pop();

        int next_truck = truck_weights[index]; // 다음에 진입할 트럭의 무게
        // 트럭이 진입할 수 있다면
        if (bridge_weight + next_truck <= weight)
        {
            bridge.push(next_truck);
            bridge_weight += next_truck;
            index++;
        }
        // 트럭이 진입할 수 없다면
        else
        {
            bridge.push(0);
        }
    }
    return time + bridge_length;
}