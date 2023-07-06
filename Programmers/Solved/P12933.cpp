#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
  long long answer = 0;

  vector<int> V;
  while(n > 0) {
    V.push_back(n % 10);
    n /= 10;
  }
  sort(V.rbegin(), V.rend());
  for(auto a : V) {
    answer *= 10;
    answer += a;
  }

  return answer;
}

int main(void) {
  vector<long long> n = {118372};

  for(auto a : n) {
    cout << solution(a) << "\n";
  }

  return 0;
}