#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double N, K, A;
double T[1001], S[1001];
double R = INT32_MAX;

int main(void) {

  cin >> N >> K >> A;
  for(int i = 1; i <= N; i++) {
    cin >> T[i] >> S[i];
    double n = floor((K-1)/(T[i]*A))*S[i] + ceil(K/A);
    //cout << floor((K-1)/(T[i]*A)) << " " << ceil(K/A) << "\n";
    R = min(R, n);
  }

  cout << R;

  return 0;
}