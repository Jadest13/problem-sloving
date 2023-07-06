#include <bits/stdc++.h>

#define MAX 101
#define INF 1000001

using namespace std;

int N;
int A[MAX];
int P[INF];
int P2[INF];
int mn = 1;
int R;
vector<int> V;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i = 2; i < INF; i++) {
    if(!P[i]) {
      P[i] = 1;
      for(int j = i*2; j < INF; j += i) {
        P[j] = -1;
      }
    }
  }

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
    int tmp = A[i];
    for(int j = 2; j < INF && tmp != 1; j++) {
      if(P[j] != 1) continue;
      while(tmp % j == 0) {
        tmp /= j;
        P2[j]++;
        if(P2[j] == N) {
          P2[j] = 0;
          V.push_back(j);
          mn *= j;
        }
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    for(auto a : V) {
      if(A[i] % a == 0) A[i] /= a;
      else R++;
    }
  }

  cout << mn << " " << R;

  return 0;
}