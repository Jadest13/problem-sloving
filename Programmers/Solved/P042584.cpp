#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;
using PII = pair<int, int>;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<PII> V;
    priority_queue<PII> PQ;
    for(int i = 0; i < prices.size(); i++) {
        while(!PQ.empty() && PQ.top().first > prices[i]) {
            V.push_back({PQ.top().second, i - PQ.top().second});
            PQ.pop();
        }
        PQ.push({prices[i], i});
    }
    while(!PQ.empty()) {
        V.push_back({PQ.top().second, prices.size()-1 - PQ.top().second});
        PQ.pop();
    }
    sort(V.begin(), V.end());
    for(auto a : V) {
        answer.push_back(a.second);
    }
    return answer;
}