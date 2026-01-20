#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int pageFaults(int N, int C, int pages[]) {
        unordered_map<int, list<int>::iterator> mp;
        list<int> lru;
        int faults = 0;

        for(int i = 0; i < N; i++) {
            int page = pages[i];
            if(mp.find(page) == mp.end()) {
                faults++;
                if(lru.size() == C) {
                    int last = lru.back();
                    lru.pop_back();
                    mp.erase(last);
                }
            } 
            else {
                lru.erase(mp[page]);
            }
            lru.push_front(page);
            mp[page] = lru.begin();
        }
        return faults;
    }
};


int main() {

    return 0;
}   