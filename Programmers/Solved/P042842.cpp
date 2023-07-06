#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i = 1; i*i <= yellow; i++) {
        if(yellow%i == 0) {
            int h = i, w = yellow/i;
            if(h*2 + w*2 + 4 == brown) {
                answer = {w+2, h+2};
                break;
            }
        }
    }
    return answer;
}