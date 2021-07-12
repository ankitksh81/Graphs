// Topological Sort using DFS in Directed Acylic Graph(DAG).

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st) {
    vis[node] = true;

    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, adj, vis, st);
        }
    }
    st.push(node);
}

void topologicalSort(vector<int> adj[], int n) {
    stack<int> st;
    vector<bool> vis(n+1, false);

    for(int i = 1; i <= n; i++) {
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }
    
    vector<int> sorted;
    while(!st.empty()) {
        sorted.push_back(st.top());
        st.pop();
    }

    for(int i: sorted) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    topologicalSort(adj, n);
    return 0;
}
