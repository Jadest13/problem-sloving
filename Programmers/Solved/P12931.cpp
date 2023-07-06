#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
  int answer = 0;

  while(n > 0) {
    answer += n % 10;
    n /= 10;
  }

  return answer;
}

int main(void) {
  vector<int> n = {123, 987};

  for(auto a : n) {
    cout << solution(a) << "\n";
  }

  return 0;
}