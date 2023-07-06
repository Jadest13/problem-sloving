#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto v : commands) {
        vector<int> V(array.begin() + v[0]-1, array.begin() + v[1]);
        sort(V.begin(), V.end());
        answer.push_back(V[v[2]-1]);
    }
    return answer;
}