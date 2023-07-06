#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 1001

using namespace std;

char A[MAX], B[MAX];
char R1[MAX+1];

char* big_add(char* A, char* B, char* R);

char* big_sub(char* A, char* B, char* R) {
  int tmp[MAX+1];
  int ri = 0, ai = strlen(A)-1, bi = strlen(B)-1;

  if(A[0] == '-') return big_sub(B, A+1, R);
  if(B[0] == '-') return big_add(A, B+1, R);
  
  for(int i = 0; i <= MAX; i++) {
    tmp[i] = 0;
  }

  while(1) {
    if(ai >= 0) {
      if(bi >= 0) {
        tmp[ri] += A[ai]-'0' + B[bi]-'0';
      } else {
        tmp[ri] += A[ai]-'0';
      }
    } else {
      if(bi >= 0) {
        tmp[ri] += B[ai]-'0';
      } else {
        if(tmp[ri] == 0)
          break;
      }
    }
    if(tmp[ri] >= 10) {
      tmp[ri] -= 10;
      tmp[ri+1]++;
    }
    ri++;
    ai--;
    bi--;
  }
  for(int i = 0; i < ri; i++) {
    R[i] = tmp[ri-i-1] + '0';
  }
  R[ri] = '\0';
  return R;
}

char* big_add(char* A, char* B, char* R) {
  int tmp[MAX+1];
  int ri = 0, ai = strlen(A)-1, bi = strlen(B)-1;
  
  if(A[0] == '-') return big_sub(B, A+1, R);
  if(B[0] == '-') return big_sub(A, B+1, R);

  for(int i = 0; i <= MAX; i++) {
    tmp[i] = 0;
  }

  while(1) {
    if(ai >= 0) {
      if(bi >= 0) {
        tmp[ri] += A[ai]-'0' + B[bi]-'0';
      } else {
        tmp[ri] += A[ai]-'0';
      }
    } else {
      if(bi >= 0) {
        tmp[ri] += B[ai]-'0';
      } else {
        if(tmp[ri] == 0)
          break;
      }
    }
    if(tmp[ri] >= 10) {
      tmp[ri] -= 10;
      tmp[ri+1]++;
    }
    ri++;
    ai--;
    bi--;
  }
  for(int i = 0; i < ri; i++) {
    R[i] = tmp[ri-i-1] + '0';
  }
  R[ri] = '\0';
  return R;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B;
  cout << big_add(A, B, R1);// << "\n" << big_sub(A, B) << "\n" << big_mul(A, B);

  return 0;
}