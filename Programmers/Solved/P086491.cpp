#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int h = 0, w = 0;
    for(auto a : sizes) {
        if(a[0] > a[1]) swap(a[0], a[1]);
        h = max(h, a[0]);
        w = max(w, a[1]);
    }
    answer = h*w;
    return answer;
}