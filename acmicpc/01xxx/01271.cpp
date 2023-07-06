#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX 1001

using namespace std;

char N[MAX], M[MAX], R[MAX];

char* big_max(char* A, char* B) {
  for(int i = 0; i < strlen(A); i++) {
    if(A[i] < B[i]) return B;
    if(A[i] > B[i]) return A;
  }
  return A;
}

void big_subtract(char* A, char* B) {
  for(int i = 0; i < strlen(B); i++) {
    A[i] = A[i] - B[i] + '0';
    if(A[i] < '0') {
      A[i] += 10;
      A[i-1]--;
    }
  }
  for(int i = strlen(B)-1; i >= 0; i--) {
    if(A[i] < '0') {
      A[i] += 10;
      A[i-1]--;
    }
  }
}

void big_divide(char* A, char* B, char* R) {
  for(int i = 0; i <= strlen(A)-strlen(B); i++) {
    R[i] = '0';
    while((i > 0 && A[i-1] > '0') || big_max(A+i, B) == A+i) {
      big_subtract(A+i, B);
      ++R[i];
    }
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  big_divide(N, M, R);

  int ri = 0, ni = 0;

  while(R[ri] == '0') ri++;
  while(N[ni] == '0') ni++;

  if(R[0] == '\0') {
    R[0] = '0';
    R[1] = '\0';
  }

  if(N[ni] == '\0') ni--;
  if(R[ri] == '\0') ri--;

  cout << R+ri << "\n" << N+ni;

  return 0;
}