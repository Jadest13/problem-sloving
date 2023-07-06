#include <iostream>
#include <algorithm>

#define MAX 10001
#define INF 1e9

using namespace std;

int N;
int A[MAX];
int sum;

int F(int n, int k) {
  if(n == sum) return 0;
  if(n > sum) return INF;

  int ret = INF;
  for(int i = 1; i <= N; i++) {
    int tmp = 0;
    if(A[i]) {
      A[i]--;
      tmp += 3;
      ret = min(ret, tmp+F(n+1));
      if(i+1 <= N && A[i+1]) {
        A[i+1]--;
        tmp += 2;
        ret = min(ret, tmp+F(n+2));
        if(i+2 <= N && A[i+2]) {
          A[i+2]--;
          tmp += 2;
          ret = min(ret, tmp+F(n+3));
          A[i+2]++;
        }
        A[i+1]++;
      }
      A[i]++;
    }
  }
  return ret;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
    sum += A[i];
  }

  cout << F(0, 0);

  return 0;
}