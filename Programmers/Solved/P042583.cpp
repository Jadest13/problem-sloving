#include <string>
#include <vector>
#include <queue>

using namespace std;
using PII = pair<int, int>;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<PII> Q;
    int W = 0;
    int S = 0;
    for(int i = 0; i < truck_weights.size(); i++) {
        int flag = 0;
        while(W + truck_weights[i] > weight) {
            S = Q.front().second + bridge_length;
            W -= Q.front().first;
            Q.pop();
            flag = 1;
        }
        if(!flag) S++;
        while(!Q.empty() && S >= Q.front().second + bridge_length) {
            S = Q.front().second + bridge_length;
            W -= Q.front().first;
            Q.pop();
        }
        Q.push({truck_weights[i], S});
        W += truck_weights[i];
    }
    while(!Q.empty()) {
        answer = Q.front().second + bridge_length;
        Q.pop();
    }
    
    return answer;
}