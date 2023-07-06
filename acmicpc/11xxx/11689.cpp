#include <iostream>
#include <vector>

#define LL long long

using namespace std;

LL N;
LL R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  R = N;
  for(LL i = 2; i*i <= N; i++) {
    if(N%i == 0) {
      while(N%i == 0) N /= i;
      R /= i;
      R *= i-1;
    }
  }
  if(N > 1) {
    R /= N;
    R *= N-1;
  }
  
  cout << R;
}