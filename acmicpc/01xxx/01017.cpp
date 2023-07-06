#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int ARR[51];
int P[2001];
vector<int> E[51];
int VA[51], VB[51];
vector<int> R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i = 2; i <= 2000; i++) {
    if(P[i] == 0) {
      P[i] = 1;
      for(int j = i*2; j <= 2000; j += i) {
        P[j] = -1;
      }
    }
  }

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> ARR[i];
  }

  for(int i = 1; i <= N; i++) {
    for(int j = i+1; j <= N; j++) {
      if(P[ARR[i]+ARR[j] == 1]) {
        E[i].push_back(j);
        E[j].push_back(i);
      }
    }
  }

  for(auto a : E[0]) {
    for(int i = 0; i < N; i++) {
      VA[i] = VB[i] = -1;
    }
    int res = 1;

    A[0] = a;
    B[a] = 0;
    A[a] = 0;
    B[0] = a;

    for(int i = 1; i < N; i++) {
      if(A[i] == -1) {
        
      }
    }
  }

  return 0;
}