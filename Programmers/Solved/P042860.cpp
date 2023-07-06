#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    int move = name.length()-1;
    
    for(int i = 0; i < name.length(); i++) {
        answer += min(name[i]-'A', 'Z'-name[i]+1);
        
        int idx = i+1;
        while(idx < name.length() && name[idx] == 'A') {
            idx++;
        }
        
        move = min(move, 2*i + (int)name.length()-idx);
        move = min(move, 2*((int)name.length()-idx) + i);
    }
    
    return answer + move;
}