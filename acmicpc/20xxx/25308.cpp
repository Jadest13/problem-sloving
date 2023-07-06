#include <iostream>
#include <algorithm>
#include <cmath>

#define R2 sqrt(2)

using namespace std;

int A[9];
int V[9];
pair<double, double> R[9];
pair<double, double> D[] = {{0, 0}, {0, 2}, {R2, R2}, {2, 0}, {R2, -R2}, {0, -2}, {-R2, -R2}, {-2, 0}, {-R2, R2}};

pair<double, double> calc(int n, int d) {
  return {D[n].first * d, D[n].second * d};
}

double ccw(double x1, double x2, double y1, double y2) {
  return x1*y2 - x2*y1;
}

int F(int n, int idx) {
  int ret = 0;
  
  if(n) {
    R[n] = calc(n, A[idx]);
    
    if(n > 2) {
      double B = ccw(R[n-1].first - R[n-2].first, R[n].first - R[n-2].first, R[n-1].second - R[n-2].second, R[n].second - R[n-2].second);
      if(B > 0) return 0;
    }


    if(n == 8) {
      if(ccw(R[n].first - R[n-1].first, R[1].first - R[n-1].first, R[n].second - R[n-1].second, R[1].second - R[n-1].second) > 0) return 0;

      if(ccw(R[1].first - R[n].first, R[2].first - R[n].first, R[1].second - R[n].second, R[2].second - R[n].second) > 0) return 0;

      return 1;
    }
  }

  for(int i = 1; i <= 8; i++) {
    if(!V[i]) {
      V[i] = 1;
      ret += F(n+1, i);
      V[i] = 0;
    }
  }
  
  return ret;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i = 1; i <= 8; i++) {
    cin >> A[i];
  }

  cout << F(0, 0);

  return 0;
}