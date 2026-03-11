#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getmincost(unordered_map<char, vector<pair<char,int>>> &graph, char src, char dst){
        priority_queue<pair<int,char>, vector<pair<int,char>>, greater<>> pq;
        pq.push({0, src});
        unordered_set<char> visited;

        while(!pq.empty()){
            auto [cost, node] = pq.top(); pq.pop();

            if(node == dst) return cost;
            if(visited.count(node)) continue;
            visited.insert(node);

            for(auto [next, wt] : graph[node]){
                if(!visited.count(next)){
                    pq.push({cost + wt, next});
                }
            }
        }
        return -1;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char,int>>> graph;
        for(int i = 0; i < original.size(); i++){
            graph[original[i]].push_back({changed[i], cost[i]});
        }

        long long result = 0;

        for(int i = 0; i < source.size(); i++){
            if(source[i] == target[i]) continue;

            int mini = getmincost(graph, source[i], target[i]);
            if(mini == -1) return -1;

            result += mini;
        }

        return result;
    }
};

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dist(26, vector<long long>(26, 1e18));
        for(int i = 0; i < 26; i++) dist[i][i] = 0;


        for(int i = 0; i < original.size(); i++){
            int u = original[i] - 'a', v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(dist[i][k] < 1e18 && dist[k][j] < 1e18){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long result = 0;

        for(int i = 0; i < source.size(); i++){
            if(source[i] == target[i]) continue;

            int u = source[i] - 'a', v = target[i] - 'a';

            if(dist[u][v] == 1e18) return -1;
            result += dist[u][v];
        }

        return result;
    }
};


int main() {

    return 0;
}