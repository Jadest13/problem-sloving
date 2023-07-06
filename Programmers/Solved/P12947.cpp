#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
  bool answer = true;
  
  int n = x;
  int sum = 0;
  while(n > 0) {
    sum += n % 10;
    n /= 10;
  }
  answer = !(x%sum);

  return answer;
}

int main(void) {
  vector<int> n = {10, 12, 11, 13};

  for(auto a : n) {
    cout << solution(a) << "\n";
  }

  return 0;
}