#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsVis){
    vis[node] = true;
    dfsVis[node] = true;

    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfs(it, adj, vis, dfsVis))
                return true;
        }
        else if(dfsVis[it]){
            return true;
        }
    }
    dfsVis[node] = false;
    return false;
}

bool isCycle(vector<int> adj[], int n) {
    vector<bool> vis(n+1, false), dfsVis(n+1, false);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(dfs(i, adj, vis, dfsVis))
                return true;
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << (isCycle(adj, n) ? "Yes\n" : "No\n");
}
