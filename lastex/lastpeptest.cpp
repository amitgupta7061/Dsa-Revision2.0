#include <bits/stdc++.h>
using namespace std;

// Question-1   max boys and girls pairs
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

// Question-2   can polycarp reach station s
int canReachStation(int s, vector<int>& a, vector<int>& b) {
    if (a[0] == 0) return 0;
    if (a[s - 1] == 1) return 1;
    if (b[s - 1] == 1) {
        for (int i = s; i < a.size(); ++i) {
            if (a[i] == 1 && b[i] == 1) return 1;
        }
    }

    return 0;
}

// Question-3   is graph bipartite
int isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);

    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int u = q.front(); q.pop();

                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } 
                    else if (color[v] == color[u]) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

// Question-4   House problem
vector<long long> countOfPairs(int n, int x, int y) {
    vector<long long> result(n, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int dist = j - i;
            int shortdist = min(abs(i - x) + 1 + abs(j - y), abs(i - y) + 1 + abs(j - x));
            
            int mini = min(dist, shortdist);
            if (mini > 0) result[mini - 1] += 2;
        }
    }
    return result;
}

// Question-5 Second Minimum Time to Reach Destination
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> first(n + 1, INT_MAX), second(n + 1, INT_MAX);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 1});
        first[1] = 0;

        while (!pq.empty()) {
            auto [currtime, node] = pq.top(); pq.pop();

            for (int neigh : adj[node]) {
                int departTime = currtime;
                if ((departTime / change) % 2 == 1) {
                    departTime = (departTime / change + 1) * change;
                }

                int arrivalTime = departTime + time;
                if (arrivalTime < first[neigh]) {
                    second[neigh] = first[neigh];
                    first[neigh] = arrivalTime;
                    pq.push({arrivalTime, neigh});
                }
                else if (arrivalTime > first[neigh] && arrivalTime < second[neigh]) {
                    second[neigh] = arrivalTime;
                    pq.push({arrivalTime, neigh});
                }
            }
        }

        return second[n];
    }
};

// Question-6  Reachable Nodes In Subdivided Graph
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {

            adj[e[0]].push_back({e[1], e[2] + 1});
            adj[e[1]].push_back({e[0], e[2] + 1});
        }

        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top(); pq.pop();
            if (d > dist[node]) continue;
            for (auto &[neigh, weight] : adj[node]) {
                if (dist[node] + weight < dist[neigh]) {
                    dist[neigh] = dist[node] + weight;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        long long result = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves) result++;
        }

        for (auto &e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            long long leftMoves = 0, rightMoves = 0;

            if (dist[u] <= maxMoves) leftMoves = maxMoves - dist[u];
            if (dist[v] <= maxMoves) rightMoves = maxMoves - dist[v];
            result += min((long long)cnt, leftMoves + rightMoves);
        }

        return result;
    }
};