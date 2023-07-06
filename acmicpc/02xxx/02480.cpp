#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int A, B, C;

int main(void) {
  cin >> A >> B >> C;

  int result;

  if(A==B && B==C) {
    result = 10000 + A*1000;  
  } else if(A==B) {
    result = 1000 + A*100;
  } else if(B==C) {
    result = 1000 + B*100;
  } else if(A==C) {
    result = 1000 + A*100;
  } else {
    if(A > B && A > C) {
      result = A*100;
    } else if(B > A && B > C) {
      result = B*100;
    } else if(C > A && C > B) {
      result = C*100;
    }
  }

  printf("%d", result);

  exit(0);
}