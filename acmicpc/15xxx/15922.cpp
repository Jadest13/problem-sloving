#include <iostream>
#include <algorithm>

#define MAX 1000001

using namespace std;
using PII = pair<int, int>;

int N;
PII ARR[MAX];
int pos;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> ARR[i].first >> ARR[i].second;
  }

  pos = ARR[1].first;
  for(int i = 1; i <= N; i++) {
    if(ARR[i].second <= pos) continue;
    if(pos < ARR[i].first) pos = ARR[i].first;
    R += ARR[i].second - pos;
    pos = ARR[i].second;
  }

  cout << R;

  return 0;
}