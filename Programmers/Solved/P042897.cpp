#include <string>
#include <vector>

#define MAX 1000001

using namespace std;

int DP[MAX][2][2];

int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();
    DP[0][0][0] = 0;
    DP[0][1][0] = 0;
    DP[0][0][1] = 0;
    DP[0][1][1] = money[0];
    for(int i = 1; i < n; i++) {
        DP[i][0][0] = max(DP[i-1][0][0], DP[i-1][1][0]);
        DP[i][1][0] = DP[i-1][0][0] + money[i];
        DP[i][0][1] = max(DP[i-1][0][1], DP[i-1][1][1]);
        DP[i][1][1] = DP[i-1][0][1] + money[i];
    }
    answer = max(DP[n-1][0][1], max(DP[n-1][0][0], DP[n-1][1][0]));
    return answer;
}