#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N, K;
deque<int> DQ;
int idx;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for(int i = 1; i <= N; i++) {
    DQ.push_back(i);
  }

  cout << "<";
  idx = K-1;
  while(!DQ.empty()) {
    int x = DQ[idx];
    cout << x << ((DQ.size()==1)?">":", ");
    DQ.erase(DQ.begin()+idx);
    idx += K-1;
    if(!DQ.empty()) idx %= DQ.size();
  }

  return 0;
}