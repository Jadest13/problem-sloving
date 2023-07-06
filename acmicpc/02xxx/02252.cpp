#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int A, B;
vector<int> E[32001];
int iD[32001];
vector<int> R;

void F() {
  queue<int> Q;

  for(int i = 1; i <= N; i++) {
    if(!iD[i]) Q.push(i);
  }

  while(!Q.empty()) {
    int p = Q.front();
    Q.pop();
    R.push_back(p);

    for(auto a : E[p]) {
      iD[a]--;
      if(!iD[a]) Q.push(a);
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for(int i = 1; i <= M; i++) {
    cin >> A >> B;
    E[A].push_back(B);
    iD[B]++;
  }

  F();

  for(auto a : R) {
    cout << a << " ";
  }

  return 0;
}