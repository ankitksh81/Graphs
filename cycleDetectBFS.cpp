#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int V, vector<int> adj[]){
    vector<int> bfs;
    vector<bool> vis(V+1, false);

    queue<pair<int, int>> q;
    vis[1] = true;
    q.push({1, -1});
    
    while(!q.empty()){
        int node = q.front().first;
        int prev = q.front().second;
        q.pop();
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push({it, node});
            }
            else if(it != prev){
                return true;
            }
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
    cout << (detectCycle(n, adj) ? "Yes\n" : "No\n");
}
