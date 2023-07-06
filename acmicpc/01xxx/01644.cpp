#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 4000001

int N;
int A[MAX];
vector<int> V;
int l, r;
int sum, R;

void Aristo() {
  for(int i = 2; i <= MAX; i++) {
    if(A[i] == 0) {
      A[i] = 1;
      for(int j = i*2; j <= MAX; j += i) {
        A[j] = -1;
      }
    }
  }

  for(int i = 2; i <= MAX; i++) {
    if(A[i] == 1) {
      V.push_back(i);
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  Aristo();
  cin >> N;

  l = 0, r = 0;
  sum = V[0];
  while(l <= r && r < V.size()) {
    if(sum < N) sum += V[++r];
    else {
      if(sum == N) R++;
      sum -= V[l++];
    }
  }

  cout << R;

  return 0;
}