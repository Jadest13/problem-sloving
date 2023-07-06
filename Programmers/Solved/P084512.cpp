#include <bits/stdc++.h>

using namespace std;

int solution(string word) {
    int answer = 0;
    string str = "";
    
    while(str != word) {
        if(str.length() < 5) {
            str += "A";
        } else {
            int idx = 4;
            while(1) {
                if(str[idx] == 'U') {
                    str.pop_back();
                    idx--;
                } else {
                    if(str[idx] == 'A') str[idx] = 'E';
                    else if(str[idx] == 'E') str[idx] = 'I';
                    else if(str[idx] == 'I') str[idx] = 'O';
                    else if(str[idx] == 'O') str[idx] = 'U';
                    break;
                }
            }
        }
        answer++;
    }
    return answer;
}