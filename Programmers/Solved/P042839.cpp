#include <bits/stdc++.h>

#define MAX 10000000

using namespace std;

int P[MAX];
int Visit[MAX];

void F(string numbers, int N, int n, int bit, string s) {
    if(n == N) {
        Visit[stoi(s)] = 1;
        return;
    }
    for(int i = 0; i < numbers.length(); i++) {
        if(bit & (1<<i)) continue;
        F(numbers, N, n+1, bit | (1<<i), s+numbers[i]);
    }
}

int solution(string numbers) {
    int answer = 0;
    
    for(int i = 2; i < MAX; i++) {
        if(P[i] == -1) continue;
        P[i] = 1;
        for(int j = i*2; j < MAX; j += i) {
            P[j] = -1;
        }
    }
    for(int i = 1; i <= numbers.size(); i++) {
        F(numbers, i, 0, 0, "");
    }
    for(int i = 1; i < MAX; i++) {
        if(Visit[i] && P[i] == 1) {
            answer++;
        }
    }
    
    return answer;
}