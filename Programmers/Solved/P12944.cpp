#include <iostream>
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
  double answer = 0;

  for(auto a : arr) answer += a;
  answer /= arr.size();

  return answer;
}

int main(void) {
  vector<vector<int>> n = {{1,2,3,4}, {5,5}};

  for(auto a : n) {
    cout << solution(a) << "\n";
  }

  return 0;
}