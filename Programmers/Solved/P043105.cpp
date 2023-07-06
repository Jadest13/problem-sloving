#include <bits/stdc++.h>

#define MAX 501

using namespace std;

int DP[MAX][MAX];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for(int i = triangle.size()-1; i >= 0; i--) {
        for(int j = 0; j < triangle[i].size(); j++) {
            DP[i][j] = triangle[i][j] + max(DP[i+1][j], DP[i+1][j+1]);
        }
    }
    
    answer = DP[0][0];
    return answer;
}