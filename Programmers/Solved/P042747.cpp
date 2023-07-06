#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for(int i = citations.size(); i >= 0; i--) {
        if(citations.size() - (lower_bound(citations.begin(), citations.end(), i) - citations.begin()) >= i) {
            answer = i;
            break;
        }
    }
    return answer;
}