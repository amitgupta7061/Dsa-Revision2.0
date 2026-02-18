#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char evaluate(string &s, char opr){
        if(opr == '!'){
            for(char ch : s){
                if(ch == 't') return 'f';
                if(ch == 'f') return 't';
            }
        }
        else if(opr == '&'){
            for(char ch : s)if(ch == 'f') return 'f';
            return 't';
        }
        else if(opr == '|'){
            for(char ch : s) if(ch == 't') return 't';
            return 'f';
        }
        return 'f';
    }

    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char ch : expression){
            if(ch == ',') continue;
            if(ch == ')'){
                string temp = "";
                while(st.top() != '('){
                    temp += st.top(); st.pop();
                }
                st.pop();
                char opr = st.top(); st.pop();
                st.push(evaluate(temp, opr));
            }
            else st.push(ch);
        }
        return st.top() == 't';
    }
};


int main() {

    return 0;
}