// Kahn's Algorithm

#include <bits/stdc++.h>
using namespace std;

void bfs(int n, vector<int> adj[], vector<int> &topo, vector<int> &inDeg){
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(inDeg[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        topo.push_back(node);
        q.pop();
        
        for(auto it: adj[node]){
            inDeg[it]--;
            if(inDeg[it] == 0){
                q.push(it);
            }
        }

    }
}

void topologicalSort(int n, vector<int> adj[], vector<int> &inDeg){
    vector<int> topo;
    bfs(n, adj, topo, inDeg);

    for(int i: topo){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n], inDeg(n, 0);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDeg[v]++;
    }
    topologicalSort(n, adj, inDeg);
    return 0;
}
