#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        int p = (sqrt(1 + 8LL*candies) - 1) / 2;
        int remaining = candies - p*(p+1) / 2;

        int row = p / num_people;
        int col = p % num_people;

        for(int i = 0; i < num_people; i++){
            result[i] = row*(i+1) + num_people*(row*(row-1)/2);
            if(i < col) result[i] += (i+1) + row*num_people;
        }
        if(col < num_people) result[col] += remaining;
        return result;
    }
};

int main() {

    return 0;
}