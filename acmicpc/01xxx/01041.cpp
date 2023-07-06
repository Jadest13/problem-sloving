#include <iostream>
#include <algorithm>

#define MAX 6+1
#define INF 51

using namespace std;
using LL = long long;

LL N;
LL ARR[MAX];
LL D1 = INF, D2 = INF*2, D3 = INF*3, D5;
int sum;
LL R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N;
  for(int i = 0; i < 6; i++) {
    cin >> ARR[i];
    D1 = min(D1, ARR[i]);
    D5 = max(ARR[i], D5);
    sum += ARR[i];
  }
  swap(ARR[3], ARR[4]);

  for(int i = 0; i < 4; i++) {
    D2 = min(D2, ARR[0]+ARR[1+i]);
    D2 = min(D2, ARR[5]+ARR[1+i]);
    D2 = min(D2, ARR[1+i%4] + ARR[1+(i+1)%4]);
  }

  for(int i = 0; i < 4; i++) {
    D3 = min(D3, ARR[1+i%4] + ARR[1+(i+1)%4]);
  }
  D3 += min(ARR[0], ARR[5]);

  if(N == 1) R = sum - D5;
  else {
    R = D3*4 + D2*4*(2*N-3) + D1*((N-2)*(N-2) + 4*(N-2)*(N-1));
  }
  cout << R;

  return 0;
}