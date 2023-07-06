#include <iostream>
#include <string>

using namespace std;

int X, A[10], I;
string S;

int main() {
  cin >> X;

  S = to_string(X);
  I = S.length() - 1;

  while(I > 0) {
    A[S.at(I)-'0']++;
    I--;
    for(int i = S.at(I)-'0'+1; i < 10; i++) {
      if(A[i] > 0) {
        A[S.at(I)-'0']++;
        S.at(I) = i + '0';
        A[i]--;
        
        for(I+=1;I<S.length();I++) {
          for(int j = 0 ; j < 10; j++) {
            if(A[j] > 0) {
              S.at(I) = j+'0';
              A[j]--;
              break;
            }
          }
        }
        I = -1;
        break;
      }
    }

  }
  
  if(I < 0) {
    cout << S;
  } else {
    cout << 0;
  }

  return 0;
}