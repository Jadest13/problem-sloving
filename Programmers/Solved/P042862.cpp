#include <string>
#include <vector>

#define MAX 32

using namespace std;

int A[MAX];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(auto a : lost) {
        A[a] += -1;
    }
    for(auto a : reserve) {
        A[a] += 1;
    }
    for(int i = 1; i <= n; i++) {
        if(A[i] == -1) {
            if(A[i-1] == 1) {
                A[i] = A[i-1] = 0;
            } else if(A[i+1] == 1) {
                A[i] = A[i+1] = 0;
            } else {
                answer++;
            }
        }
    }
    answer = n - answer;
    return answer;
}