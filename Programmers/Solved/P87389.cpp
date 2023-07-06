#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;

  for(int i = 2; i < n; i++) {
    if(n % i == 1) {
      answer = i;
      break;
    }
  }

  return answer;
}

int main(void) {
  vector<int> n = {10, 12};

  for(auto a : n) {
    cout << solution(a) << "\n";
  }

  return 0;
}