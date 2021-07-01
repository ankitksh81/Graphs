#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<bool> &vis, vector<int> adj[], vector<int> &dfs){
    dfs.push_back(node);
    vis[node] = true;
    for(auto it: adj[node]){
        if(!vis[it]){
            DFS(it, vis, adj, dfs);
        }
    }
}

void printDFS(int V, vector<int> adj[]){
    vector<int> dfs;
    vector<bool> vis(V+1, false);

    DFS(1, vis, adj, dfs);
    
    for(auto it: dfs){
        cout << it << " ";
    }
    cout << "\n";
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    printDFS(n, adj);
}
