#include <bits/stdc++.h>
using namespace std;


int main() {

    int n;
    cin >> n;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int result = 0;

    for(int i = 0; i < n; i++){
        int score;
        cin >> score;

        if(mini == INT_MAX){
            mini = min(mini, score);
            maxi = max(maxi, score);
        }
        else {
            if(score > maxi){
                result++;
                maxi = score;
            } else if(score < mini){
                result++;
                mini = score;
            }
        }
    }

    cout<<result;

    return 0;
}