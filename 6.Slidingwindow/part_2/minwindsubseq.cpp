#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int n = s1.length(), m = s2.length(), mini = INT_MAX, start = -1;
        
        for (int i = 0; i <= n - m; i++) {

            if (s1[i] == s2[0]) {
                int j = 0, k = i;
                
                // Forward pass
                while (k < n && j < m) {
                    if (s1[k] == s2[j]) j++;
                    k++;
                }
                
                if (j == m) {
                    int end = k - 1;
                    
                    // Backward pass
                    j = m - 1;
                    k = end;
                    while (k >= i && j >= 0) {
                        if (s1[k] == s2[j])  j--;
                        k--;
                    }
                    
                    int newStart = k + 1;
                    int windowLen = end - newStart + 1;
                    
                    if (windowLen < mini) {
                        mini = windowLen;
                        start = newStart;
                    }
                    i = newStart;
                }
            }
        }
        
        return start == -1 ? "" : s1.substr(start, mini);
    }
};

int main() {

    return 0;
}