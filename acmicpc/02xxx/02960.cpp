#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int A[1001];
int N, K;

int main(void) {

  int result = 0;
  int T = 0;

  cin >> N >> K;

  for(int i = 2; i <= N; i++) {
    if(A[i] >= 0) {
      A[i] = 1;
      T++;
      if(T == K) {
        result = i;
        break;
      }
      for(int j = i*2; j <= N; j += i) {
        if(A[j] == 0) {
          T++;
          if(T == K) {
            result = j;
            break;
          }
        }
        A[j] = -1;
      }
      if(result) break;
    }
  }


  printf("%d", result);

  exit(0);
}