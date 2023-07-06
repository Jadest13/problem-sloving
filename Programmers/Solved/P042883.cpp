#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for(int i = 1; i <= k; i++) {
        int flag = 0;
        for(int j = 0; j < number.length()-1; j++) {
            if(number[j] < number[j+1]) {
                flag = 1;
                number.erase(number.begin()+j);
                break;
            }
        }
        if(flag) continue;
        number.pop_back();
    }
    answer = number;
    return answer;
}