// Strongly connected components

#include <bits/stdc++.h>
using namespace std;

// dfs for topological sorting
void dfs(int node, stack<int> &st, vector<bool> &vis, vector<int> adj[]) {
    vis[node] = true;

    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj);
        }
    }
    st.push(node);
}

// dfs for getting next connected componenets
void revDfs(int node, vector<bool> &vis, vector<int> transpose[]) {
    cout << node << " ";
    vis[node] = 1;

    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose);
        }
    }
}

// function to do initializations and print scc
void scc(int n, vector<int> adj[]) {
    vector<bool> vis(n, false);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, st, vis, adj);
        }
    }

    vector<int> transpose[n];

    for(int i = 0; i < n; i++) {
        vis[i] = false;
        for(auto it: adj[i]) {
            transpose[it].push_back(i);
        }
    }

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if(!vis[node]) {
            cout << "SCC: ";
            revDfs(node, vis, transpose);
            cout << "\n";
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
    }

    scc(n, adj);

    return 0;
}
