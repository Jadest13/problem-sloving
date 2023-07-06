#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500001

typedef long long LL;

using namespace std;

int N;
int A[MAX];

LL merge(int s, int e) {
  int m = (s+e)/2;
  int l = s;
  int r = m+1;
  vector<int> tmp;
  LL ret = 0;

  if(s==e) return 0;
  ret += merge(s, m);
  ret += merge(m+1, e);

  while(l <= m && r <= e) {
    if(A[l] <= A[r]) {
      tmp.push_back(A[l++]);
    } else {
      tmp.push_back(A[r++]);
      ret += m+1-l;
    }
  }

  while(l <= m) tmp.push_back(A[l++]);
  while(r <= e) tmp.push_back(A[r++]);

  for(int i = s; i <= e; i++) {
    A[i] = tmp[i-s];
  }

  return ret;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  cout << merge(0, N-1);

  return 0;
}