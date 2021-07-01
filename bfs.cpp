#include <bits/stdc++.h>
using namespace std;

void printBFS(int V, vector<int> adj[]){
    vector<int> bfs;
    vector<bool> vis(V+1, false);

    queue<int> q;
    vis[1] = true;
    q.push(1);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = true;
            }
        }
    }

    for(auto it: bfs){
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
    printBFS(n, adj);
}
