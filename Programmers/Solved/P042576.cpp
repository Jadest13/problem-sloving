#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multiset<string> SET;
    for(auto a : participant) {
        SET.insert(a);
    }
    for(auto a : completion) {
        SET.erase(SET.find(a));
    }
    answer = *SET.begin();
    return answer;
}