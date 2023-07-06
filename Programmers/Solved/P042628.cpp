#include <string>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    int size = 0;
    priority_queue<int> PQmx;
    priority_queue<int, vector<int>, greater<int>> PQmn;
    for(auto str : operations) {
        int a = stoi(str.substr(2));
        if(str[0] == 'I') {
            size++;
            PQmx.push(a);
            PQmn.push(a);
        } else {
            if(size == 0) continue;
            if(a < 0) {
                PQmn.pop();
            } else {
                PQmx.pop();
            }
            size--;
            
            if(size == 0) {
                while(!PQmx.empty()) PQmx.pop();
                while(!PQmn.empty()) PQmn.pop();
            }
        }
    }
    if(size == 0) {
        PQmx.push(0);
        PQmn.push(0);
    }
    answer.push_back(PQmx.top());
    answer.push_back(PQmn.top());
    
    return answer;
}