#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int node, int prev, vector<bool>& vis, vector<int> adj[]){
    vis[node] = true;
    for(auto it: adj[node]){
        if(!vis[it]){
            vis[it] = true;
            if(detectCycle(it, node, vis, adj))
                return true;
        }
        else if(it != prev){
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
        adj[v].push_back(u);
    }
    vector<bool> vis(n+1, false);
    cout << (detectCycle(1, -1, vis, adj) ? "Yes\n" : "No\n");
}
