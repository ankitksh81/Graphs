#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int parent, int &timer, vector<bool> &vis, vector<int> &low, vector<int> &tin, vector<int> &isArticulation, vector<int> adj[]) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;

    for(auto it: adj[v]) {
        if(it == parent)
            continue;
        if(vis[it]) {
            low[v] = min(low[v], tin[it]);
        } else {
            dfs(it, v, timer, vis, low, tin, isArticulation, adj);
            low[v] = min(low[v], low[it]);

            // Important condition to check if the node is a articulation point
            if(low[it] >= tin[v] && parent != -1) { 
                isArticulation[v] = 1;
            }
            ++children;
        }
    }

    if(parent == -1 && children > 1) {
        isArticulation[v] = 1;
    }
}

void is_cutpoint(int n, vector<int>& isArticulation) {
    for(int i = 0; i < n; i++) {
        if(isArticulation[i]) {
            cout << i << "\n";
        }
    }
}

// function to do all the necessary initialization and start the dfs
void find_cutpoints(int n, vector<int> adj[], vector<int>& tin, vector<int>& low, vector<bool>& vis, vector<int>& isArticulation) {
    int timer = 0;
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    isArticulation.assign(n, 0);

    for(int i = 0; i < n; ++i) {
        if(!vis[i]){
            dfs(i, -1, timer, vis, low, tin, isArticulation, adj);
        }
    }

    is_cutpoint(n, isArticulation);
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

    vector<int> tin, low, isArticulation;
    vector<bool> vis;

    find_cutpoints(n, adj, tin, low, vis, isArticulation);

    return 0;
}
