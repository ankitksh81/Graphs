#include <bits/stdc++.h>
using namespace std;

// node definition for storing the edges
struct node {
    int u, v, wt;
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

// function to sort the edges by weights
bool comp(node a, node b) {
    return a.wt < b.wt;
}

// function to find the parent of a node
int findParent(int x, vector<int> &parent) {
    if(x == parent[x]){
        return x;
    }
    // return parent[x] = findParent(parent[x], parent);
    return findParent(parent[x], parent);
}

// function to make union of 2 nodes
void unionNode(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<node> edges;

    for(int i = 0; i < m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(n), rank(n, 0);

    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int cost = 0;
    vector<pair<int, int>> mst;

    for(auto it: edges) {
        if(findParent(it.v, parent) != findParent(it.u, parent)) {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionNode(it.u, it.v, parent, rank);
        }
    }

    cout << cost << "\n";

    for(auto it: mst){
        cout << it.first << " - " << it.second << "\n";
    }

    return 0;
}