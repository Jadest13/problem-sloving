#include <string>
#include <vector>

using namespace std;

int DFS(vector<int> numbers, int n, int a, int target) {
    if(n == numbers.size()) {
        if(a == target) return 1;
        else return 0;
    }
    return DFS(numbers, n+1, a+numbers[n], target) + DFS(numbers, n+1, a-numbers[n], target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer = DFS(numbers, 0, 0, target);
    return answer;
}