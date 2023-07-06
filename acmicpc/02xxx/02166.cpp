#include <iostream>
#include <algorithm>

using namespace std;

int N;
long x, y;
vector<pair<long, long>> V;
double R;
double X, Y;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> x >> y;
    V.push_back({x, y});
  }
  V.push_back(V[0]);
  
  for(int i = 0; i < N; i++) {
    X += V[i].first*V[i+1].second;
    Y += V[i].second*V[i+1].first;
  }

  R = (X - Y)/2.0;

  cout << fixed;
  cout.precision(1);
  cout << abs(R);

  return 0;
}