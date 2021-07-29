// Shortest Path in Undirected Graphs

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, src;
    cin >> n >> m;

    vector<pair<int, int>> adj[n+1];

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u, w});
    }

    cin >> src;

    // Dijkstra's algorithm begins from here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> distTo(n+1, INT_MAX);

    distTo[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        for(auto it = adj[prev].begin(); it != adj[prev].end(); it++){
            int next = it->first;
            int nextDist = it->second;

            if(distTo[next] > distTo[prev] + nextDist){
                distTo[next] = distTo[prev] + nextDist;
                // distTo[next] = min(distTo[next], distTo[prev]+nextDist);
                pq.push({distTo[next], next});
            }
        }
    }

    cout << "Distances from source, " << src << ", are : \n";
    for(int i = 1; i <= n; i++){
        cout << distTo[i] << " ";
    }
    cout << "\n";
    return 0;
}
