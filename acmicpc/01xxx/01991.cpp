#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
char a, b, c;
vector<int> T[100];

string preorder(char A, string s) {
  if(A == '.') return s;

  s += A;
  for(auto a : T[A]) {
    s += preorder(a, "");
  }
  return s;
}

string inorder(char A, string s) {
  if(A == '.') return s;

  if(T[A].size() >= 1) s += inorder(T[A][0], "");
  s += A;
  if(T[A].size() >= 2) s += inorder(T[A][1], "");

  return s;
}

string postorder(char A, string s) {
  if(A == '.') return s;
  
  for(auto a : T[A]) {
    s += postorder(a, "");
  }
  s += A;
  return s;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> a >> b >> c;
    T[a].push_back(b);
    T[a].push_back(c);
  }

  cout << preorder('A', "") << "\n";
  cout << inorder('A', "") << "\n";
  cout << postorder('A', "") << "\n";

  return 0;
}