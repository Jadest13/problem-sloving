#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int idx = 0;
    for(int i = 0; i <= 100 && idx < speeds.size(); i++) {
        int num = 0;
        while(idx < speeds.size() && progresses[idx] + speeds[idx]*i >= 100) {
            idx++;
            num++;
        }
        if(num > 0) answer.push_back(num);
    }
    return answer;
}