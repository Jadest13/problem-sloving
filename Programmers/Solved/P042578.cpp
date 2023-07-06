#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> MP;
    for(auto a : clothes) {
        MP[a[1]]++;
    }
    for(auto a : MP) {
        answer *= (a.second + 1);
    }
    answer -= 1;
    return answer;
}