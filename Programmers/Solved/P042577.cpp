#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> S;
    for(auto a : phone_book) {
        S.insert(a);
    }

    for(auto it1 = S.begin(); it1 != S.end(); it1++) {
        for(auto it2 = it1; it2 != S.end(); it2++) {
            if(it1 != it2) {
                if(it2->find(*it1) == 0) {
                    answer = false;
                } else {
                    break;
                }
            }
        }
    }
    return answer;
}