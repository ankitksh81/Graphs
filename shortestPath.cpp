// Shortest Path in undirected graph with unit weight.

#include <bits/stdc++.h>
using namespace std;

void shortestPath(int n, vector<int> adj[]){
    vector<int> dist(n, INT_MAX);
    queue<int> q;

    int src = 0; // Source taken as 0
    dist[src] = 0;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            dist[it] = min(dist[it], dist[node]+1);
            q.push(it);
        }
    }

    for(int i = 0; i < n; i++){
        cout << i << ": " << dist[i] << "\n";
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    shortestPath(n, adj);
    return 0;
}
