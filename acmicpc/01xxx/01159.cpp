#include <iostream>
#include <algorithm>

using namespace std;

int N;
string str;
int A[26];
int flag;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  while(N--) {
    cin >> str;
    A[str[0]-'a']++;
  }
  for(int i = 0; i < 26; i++) {
    if(A[i] >= 5) {
      flag = 1;
      cout << (char)(i+'a');
    }
  }
  if(!flag) cout << "PREDAJA";

  return 0;
}