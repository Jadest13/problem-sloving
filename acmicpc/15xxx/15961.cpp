#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 3000001
#define INF 1e15

using namespace std;
using LL = long long;

int N;
int d, k, c;
int A[MAX];
int B[MAX];
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N;
  cin >> d >> k >> c;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int tmp = 0;
  for(int i = 0; i < k; i++) {
    if(!B[A[i]]) {
      tmp++;
    }
    B[A[i]]++;
  }
  int l = 0, r = (l+k)%N;
  while(l < N) {
    if(!B[c]) R = max(R, tmp+1);
    else R = max(R, tmp);
    
    B[A[l]]--;
    if(!B[A[l]]) tmp--;
    if(!B[A[r]]) tmp++;
    B[A[r]]++;

    l++;
    r++;
    r %= N;
  }

  cout << R;
  
  return 0;
}