#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
  vector<int> answer;

  while(n > 0) {
    answer.push_back(n%10);
    n /= 10;
  }

  return answer;
}

int main(void) {
  vector<long long> n = {12345};

  for(auto a : n) {
    //cout << solution(a) << "\n";
  }

  return 0;
}