#include <iostream>
#include <algorithm>

using namespace std;

int N;
int sum;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i = 1; i <= 10; i++) {
    cin >> N;
    sum += N;
    if(abs(100-sum) < abs(100-R)) R = sum;
    else if (abs(100-sum) == abs(100-R)) {
      R = max(R, sum);
    }
  }
  
  cout << R;

  return 0;
}