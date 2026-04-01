#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string encode(vector<string> &strs) {
        string result = "";
        for(string &s : strs){
            string length = to_string(s.length());
            result += (length + "#" + s);
        }
        return result;
    }

    vector<string> decode(string &str) {
        vector<string> result;
        int i = 0;
        int n = str.length();

        while(i < n){

            int j = i;
            string len = "";
            while(str[j] != '#'){
                len += str[j];
                j++;
            }
            j++;

            int length = stoi(len);

            string s;
            while(length--){
                s += str[j];
                j++;
            }
            result.push_back(s);

            i = j;
        }

        return result;
    }
};

int main() {

    return 0;
}