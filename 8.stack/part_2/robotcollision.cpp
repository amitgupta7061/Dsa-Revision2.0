#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<tuple<int,int,char,int>> robots;
        
        for(int i = 0; i < n; i++){
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end());

        stack<int> st;

        for(int i = 0; i < n; i++){
            if(get<2>(robots[i]) == 'R'){
                st.push(i);
            } else {
                while(!st.empty() && get<1>(robots[i]) > 0){
                    int j = st.top();

                    if(get<1>(robots[j]) < get<1>(robots[i])){
                        get<1>(robots[i])--;
                        get<1>(robots[j]) = 0;
                        st.pop();
                    }
                    else if(get<1>(robots[j]) > get<1>(robots[i])){
                        get<1>(robots[j])--;
                        get<1>(robots[i]) = 0;
                    }
                    else{
                        get<1>(robots[j]) = 0;
                        get<1>(robots[i]) = 0;
                        st.pop();
                    }
                }
            }
        }

        vector<pair<int,int>> survivors;

        for(int i = 0; i < n; i++){
            if(get<1>(robots[i]) > 0){
                survivors.push_back({get<3>(robots[i]), get<1>(robots[i])});
            }
        }

        sort(survivors.begin(), survivors.end());

        vector<int> result;
        for(auto &p : survivors){
            result.push_back(p.second);
        }

        return result;
    }
};

int main() {

    return 0;
}
