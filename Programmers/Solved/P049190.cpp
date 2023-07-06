#include <bits/stdc++.h>

#define MAX 1000001

using namespace std;

int solution(vector<int> arrows) {
    int answer = 0;
    map<pair<int, int>, int> MP;
    map<pair<pair<int, int>, pair<int, int>>, int> E;
    pair<int, int> D[] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    int x = 0, y = 0;
    MP[{x, y}] = 1;
    for(auto a : arrows) {
        for(int i = 0; i < 2; i++) {
            int nx = x + D[a].first;
            int ny = y + D[a].second;
            if(!E[{{x, y}, {nx, ny}}] && !E[{{nx, ny}, {x, y}}])
                if(MP[{nx, ny}]) answer++;
            MP[{nx, ny}]++;
            E[{{x, y}, {nx, ny}}]++;
            x = nx;
            y = ny;
        }
    }
    return answer;
}