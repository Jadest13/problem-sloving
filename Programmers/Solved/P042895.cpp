#include <string>
#include <vector>

using namespace std;

vector<int> DP[10];

int solution(int N, int number) {
    int answer = -1;
    for(int i = 1; i <= 8; i++) {
        DP[i].push_back(0);
        for(int j = 1; j <= i; j++) {
            DP[i][0] *= 10;
            DP[i][0] += N;
        }
        for(int j = 1; j < i; j++) {
            for(auto a : DP[j]) {
                for(auto b : DP[i-j]) {
                    if(b==0) continue;
                    DP[i].push_back(a/b);
                    DP[i].push_back(a*b);
                    DP[i].push_back(a+b);
                    DP[i].push_back(a-b);
                }
            }
        }
        for(auto a : DP[i]) {
            if(number == a) {
                answer = i;
                break;
            }
        }
        if(answer > 0) break;
    }
    return answer;
}