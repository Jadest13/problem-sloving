#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> PQ;
    for(auto a : scoville) {
        PQ.push(a);
    }
    while(PQ.top() < K) {
        if(PQ.size() < 2) {
            answer = -1;
            break;
        }
        int a1, a2;
        a1 = PQ.top();
        PQ.pop();
        a2 = PQ.top();
        PQ.pop();
        PQ.push(a1 + a2*2);
        answer++;
    }
    return answer;
}