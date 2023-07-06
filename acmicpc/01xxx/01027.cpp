#include <iostream>
#include <algorithm>
#include <map>

#define MAX 51
#define INF -1e9 -1

using namespace std;
using PID = pair<int, double>;

int N;
int ARR[MAX];
PID tmp[MAX];

int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> ARR[i];
    tmp[i] = {0, INF};

    for(int j = 1; j < i; j++) {
      double a = (double)(ARR[i]-ARR[j])/(i-j);
      if(tmp[j].second < a) {
        tmp[j].first++;
        tmp[j].second = a;
        tmp[i].first++;
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    R = max(R, tmp[i].first);
  }

  cout << R;

  return 0;
}