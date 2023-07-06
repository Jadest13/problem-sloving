#include <iostream>
#include <cstring>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int arr[51][51], check[51][51];
int T, M, N, K, X, Y;
int R;

void dfs(int x, int y) {
  check[y][x] = 1;
  for(int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx >= 0 && ny >= 0 && nx < M && ny < N) {
      if(arr[ny][nx] && !check[ny][nx]) {
        dfs(nx, ny);
      }
    }
  }
}

int main() {
  
  cin >> T;
  
  for(int i = 0; i < T; i++) {
    memset(arr, 0, sizeof(arr));
    memset(check, 0, sizeof(check));
    R = 0;

    cin >> M >> N >> K;
    for(int j = 0; j < K; j++) {
      cin >> X >> Y;
      arr[Y][X] = 1;
    }

    for(int j = 0; j < N; j++) {
      for(int k = 0; k < M; k++) {
        if(arr[j][k] && !check[j][k]) {
          R++;
          dfs(k, j);
        }
      }
    }


    cout << R << endl;
  }

  return 0;
}