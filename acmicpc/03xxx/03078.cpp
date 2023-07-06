#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 300001

using namespace std;
using LL = long long;

int N, K;
string str;
int A[MAX];
int B[21];
LL R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for(int i = 1; i <= N; i++) {
    cin >> str;
    A[i] = str.length();
  }
  for(int i = 1; i <= K; i++) {
    B[A[i]]++;
  }
  int l = 1, r = K+1;
  while(l <= N) {
    if(r <= N) {
      B[A[r]]++;
    }
    R += (B[A[l]]-1);
    B[A[l]]--;
    l++;
    r++;
  }

  cout << R;
  
  return 0;
}