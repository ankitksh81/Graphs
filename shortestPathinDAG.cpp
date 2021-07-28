// Shortest Path in a weighted DAG

#include <bits/stdc++.h>
using namespace std;

void topoSort(int src, vector<pair<int, int>> adj[], vector<bool> &vis, stack<int> &st){
    vis[src] = true;
    for(auto it: adj[src]){
        if(!vis[it.first]){
            topoSort(it.first, adj, vis, st);
        }
    }
    st.push(src);
}

void shortestPath(int src, int V, vector<pair<int, int>> adj[]){
    vector<bool> vis(V, false);
    vector<int> dist(V, INT_MAX);
    stack<int> st;
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            topoSort(i, adj, vis, st);
        }
    }
    
    dist[src] = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(dist[node] != INT_MAX){
            for(auto it: adj[node]){
                if(dist[it.first] > dist[node] + it.second){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    for(int i = 0; i < V; i++){
        (dist[i] == INT_MAX) ? cout << "INF " : cout << dist[i] << " ";
    }
    cout << "\n";
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for(int i = 0; i < m; i++){
       int u, v, w;
       cin >> u >> v >> w;
       adj[u].push_back({v, w});
    }
    shortestPath(0, n, adj);
}
