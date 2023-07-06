#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int A;
vector<int> E[51];
int root, d;
int R;

void F(int n) {
  int ret = 0;

  if(n==d) return;

  if(E[n].empty()) {
    R++;
  }

  if(E[n].size() == 1) {
    if(E[n].front() == d) {
      R++;
      return;
    }
  }

  for(int i = 0; i < E[n].size(); i++) {
    if(E[n][i] != d) {
      F(E[n][i]);
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A;
    if(A == -1) root = i;
    else {
      E[A].push_back(i);
    }
  }
  cin >> d;
  F(root);
  cout << R;

  return 0;
}