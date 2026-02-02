#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string result = "";
        for(int curr = 0, next = curr+1; curr < word.size();){
            while(next < word.size() and word[next] == word[curr]) next++;

            int cnt = next - curr;
            while(cnt > 9){
                result += "9";
                result += word[curr];
                cnt -= 9;
            }
            result += "9";
            result += word[curr];
            curr = next;
        }
        return result;
    }
};

int main() {

    return 0;
}