// Minimum Spanning Tree in weighted undirected graph

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> parent(n, -1), key(n, INT_MAX);
    vector<bool> mst(n, false);

    key[0] = 0;
    parent[0] = -1;

    for(int edges = 0; edges < n-1; edges++){
        int mini = INT_MAX, u;

        for(int i = 0; i < n; i++){
            if(mst[i] == false && key[i] < mini){
                mini = key[i], u = i;
            }
        }

        mst[u] = true;

        for(auto it: adj[u]){
            int v = it.first;
            int wt = it.second;

            if(mst[v] == false && wt < key[v]){
                parent[v] = u, key[v] = wt;
            }
        }
    }

    for(int i = 1; i < n; i++){
        cout << parent[i] << " - " << i << " \n";
    }
    return 0;
}
