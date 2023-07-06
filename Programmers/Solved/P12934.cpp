#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
  long long answer = 0;

  long long a = sqrt(n);
  if(pow(a, 2) != n) {
    answer = -1;
  } else {
    answer = pow(a+1, 2);
  }

  return answer;
}

int main(void) {
  vector<int> n = {121, 3};

  for(auto a : n) {
    cout << solution(a) << "\n";
  }

  return 0;
}