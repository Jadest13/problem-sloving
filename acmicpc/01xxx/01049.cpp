#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N, M;
int Lset = 1001, Lone = 1001;

int main(void) {

  cin >> N >> M;

  for(int i = 0 ; i < M; i++) {
    int A, B;
    cin >> A >> B;
    Lset = min(A, Lset);
    Lone = min(B, Lone);
  }

  int set = N / 6;
  int one = N % 6;
  
  int result;
  if(Lone * 6 < Lset) {
    result = Lone*N;
  } else {
    if(Lset < one*Lone) {
      result = (set+1)*Lset;
    } else {
      result = set*Lset + one*Lone;
    }
  }

  printf("%d\n", result);

  exit(0);
}