#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int inorder[100001], postorder[100001], I[100001];

void F(int is, int ie, int ps, int pe) {

  if(is > ie || ps > pe) return;

  int root = I[postorder[pe]];

  cout << postorder[pe] << " ";

  F(is, root - 1, ps, ps + (root-is) -1);
  F(root + 1, ie, ps + (root-is), pe - 1);
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> inorder[i];
    I[inorder[i]] = i;
  }
  for(int i = 1; i <= N; i++) {
    cin >> postorder[i];
  }

  F(1, N, 1, N);

  return 0;
}