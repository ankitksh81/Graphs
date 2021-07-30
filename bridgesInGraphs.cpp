#include <bits/stdc++.h>
using namespace std;

void is_bridge(int u, int v) {
    cout << u << " - " << v << "\n";
}

void dfs(int v, int parent, int &timer, vector<bool>& vis, vector<int>& low, vector<int>& tin, vector<int> adj[]) {
    vis[v] = true;
    tin[v] = low[v] = timer++;

    for(auto it: adj[v]) {
        if(it == parent)
            continue;
        if(vis[it]) {
            low[v] = min(low[v], tin[it]);
        } else {
            dfs(it, v, timer, vis, low, tin, adj);
            low[v] = min(low[v], low[it]);
            if(low[it] > tin[v])
                is_bridge(v, it);
        }
    }
}

void find_bridges(int n, vector<int> adj[], vector<int>& tin, vector<int>& low, vector<bool>& vis) {
    int timer = 0;
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);

    for(int i = 0; i < n; ++i) {
        if(!vis[i]){
            dfs(i, -1, timer, vis, low, tin, adj);
        }
    }
}

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tin, low;
    vector<bool> vis;

    find_bridges(n, adj, tin, low, vis);

    return 0;
}