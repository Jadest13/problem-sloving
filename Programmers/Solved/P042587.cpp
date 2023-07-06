#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
using PII = pair<int, int>;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<PII> Q;
    map<int, int> MP;

    for(int i = 0; i < priorities.size(); i++) {
        Q.push({priorities[i], i});
        MP[priorities[i]]++;
    }

    while(!Q.empty()) {
        PII a = Q.front();
        Q.pop();
        
        if(a.first < MP.rbegin()->first) {
            Q.push(a);
        } else {
            MP[a.first]--;
            if(MP[a.first] == 0) {
                MP.erase(MP.find(a.first));
            }
            answer++;
            if(a.second == location) {
                break;   
            }
        }
    }

    return answer;
}