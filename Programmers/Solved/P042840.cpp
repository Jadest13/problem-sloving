#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> Z[3] = {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    int R[3] = {0, };
    
    for(int i = 0; i < answers.size(); i++) {
        for(int j = 0; j < 3; j++) {
            if(answers[i] == Z[j][i%Z[j].size()]) R[j]++;
        }
    }
    int mx = max(R[0], max(R[1], R[2]));
    for(int i = 0; i < 3; i++) {
        if(R[i] == mx) answer.push_back(i+1);
    }
    
    return answer;
}