#include <bits/stdc++.h>

#define MAX 102
#define INF 1e9

using namespace std;

int solution(vector<string> arr)
{
    int answer = -1;
    vector<int> N;
    vector<char> O;
    int DPmn[MAX][MAX], DPmx[MAX][MAX];
    
    for(int i = 0; i < arr.size(); i++) {
        if(i%2 == 0) {
            N.push_back(stoi(arr[i]));
        } else {
            O.push_back(arr[i][0]);
        }
    }
    
    for(int i = 0; i < N.size(); i++) {
        for(int j = 0; j < N.size(); j++) {
            DPmx[i][j] = -INF;
            DPmn[i][j] = INF;
        }
    }
    
    for(int i = 0; i < N.size(); i++) {
        for(int j = 0; j < N.size() - i; j++) {
            if(i == 0) {
                DPmx[j][j] = N[j];
                DPmn[j][j] = N[j];
                continue;
            }
            for(int k = j; k < j+i; k++) {
                if(O[k] == '+') {
                    DPmx[j][j+i] = max(DPmx[j][j+i], DPmx[j][k] + DPmx[k+1][j+i]);
                    DPmn[j][j+i] = min(DPmn[j][j+i], DPmn[j][k] + DPmn[k+1][j+i]);
                } else {
                    DPmx[j][j+i] = max(DPmx[j][j+i], DPmx[j][k] - DPmn[k+1][j+i]);
                    DPmn[j][j+i] = min(DPmn[j][j+i], DPmn[j][k] - DPmx[k+1][j+i]);
                }
            }
        }
    }
    answer = DPmx[0][N.size()-1];
    
    return answer;
}