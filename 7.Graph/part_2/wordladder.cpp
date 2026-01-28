#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> list(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.emplace(beginWord, 1);
        if(list.count(beginWord)) list.erase(beginWord);

        while(q.size()){
            auto [curr, step] = q.front(); q.pop();
            if(curr == endWord) return step;

            for(int i = 0; i < curr.size(); i++){
                char orgchar = curr[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    curr[i] = ch;
                    if(list.count(curr)){
                        list.erase(curr);
                        q.push({curr, step+1});
                    }
                }
                curr[i] = orgchar;
            }
        }
        return 0;
    }
};

int main() {

    return 0;
}