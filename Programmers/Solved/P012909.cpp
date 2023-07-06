#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int num = 0;
    for(auto a : s) {
        if(a == '(') {
            num++;
        } else {
            num--;
        }
        if(num < 0) break;
    }
    if(num) answer = false;

    return answer;
}