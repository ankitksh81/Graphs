#include <bits/stdc++.h>
using namespace std;

bool bfs(int n, vector<int> adj[], vector<int> &topo, vector<int> &inDeg){
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(inDeg[i] == 0){
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int node = q.front();
        topo.push_back(node);
        q.pop();
        cnt++;
        for(auto it: adj[node]){
            inDeg[it]--;
            if(inDeg[it] == 0){
                q.push(it);
            }
        }
    }
    
    if(cnt == n){
        return false;
    }
    return true;
}

void topologicalSort(int n, vector<int> adj[], vector<int> &inDeg){
    vector<int> topo;
    cout << (bfs(n, adj, topo, inDeg) ? "Yes\n" : "No\n");
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
