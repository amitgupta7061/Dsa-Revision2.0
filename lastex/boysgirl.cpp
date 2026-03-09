#include <bits/stdc++.h>
using namespace std;

int getMaxpairs(vector<int>& boys, vector<int>& girls) {
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    int i = 0, j = 0, cnt = 0;
    while (i < boys.size() && j < girls.size()) {
        if (abs(boys[i] - girls[j]) <= 1) {
            cnt++; i++; j++;
        } 
        else if (boys[i] < girls[j]) i++;
        else j++;
    }
    return cnt;
}

int main() {

    vector<int> boys = {3, 1, 4, 6, 2};
    vector<int> girls = {5, 1, 3, 7, 2, 4};

    cout<<getMaxpairs(boys, girls);

    return 0;
}