#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int>& color, vector<int> adj[]){
    if(color[node] == -1) {
        color[node] = 1;
    }
    for(auto it: adj[node]){
        if(color[it] == -1){
            color[it] = 1 - color[node];
            if(!dfs(it, color, adj)) {
                return false;
            }
        }
        else if(color[it] == color[node]) {
            return false;
        }
    }
    return true;
}

bool isBipartite(int n, vector<int> adj[]) {
    vector<int> color(n+1, -1);

    if(!dfs(1, color, adj)) {
        return false;
    }
    return true;
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
    bool ans = isBipartite(n, adj);
    cout << (ans ? "YES" : "NO") << "\n";
}
