#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> V;
    for(auto a : numbers) {
        V.push_back(to_string(a));
    }
    sort(V.begin(), V.end(), [](string a, string b) {
        return a+b > b+a;
    });
    for(auto a : V) {
        answer += a;
    }
    while(!answer.empty() && answer[0] == '0') {
        answer.erase(answer.begin());
    }
    if(answer.empty()) {
        answer = "0";
    }
    
    return answer;
}