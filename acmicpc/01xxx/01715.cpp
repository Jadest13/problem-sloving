#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100001

using namespace std;

int N;
int a, b;
priority_queue<int, vector<int>, greater<int>> PQ;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for(int i = 0; i < N; i++) {
    cin >> a;
    PQ.push(a);
  }

  while(PQ.size() > 1) {
    a = PQ.top();
    PQ.pop();
    b = PQ.top();
    PQ.pop();
    R += a+b;
    PQ.push(a+b);
  }

  cout << R << "\n";

  return 0;
}