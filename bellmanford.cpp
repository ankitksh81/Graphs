#include <bits/stdc++.h>
using namespace std;

struct node {
    int u, v, wt;
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};


int main(){
    int n, m;
    cin >> n >> m;
    vector<node> edges;

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    int src;
    cin >> src;

    vector<int> dist;
    dist.assign(n, INT_MAX);
    dist[src]= 0;

    // relaxing all the edges n-1 times
    for(int i = 1; i < n; i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    // checking for negative cycle
    bool flag = false;
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            flag = true;
            break;
        }
    }

    if(!flag) {
        for(int i = 0; i < n; i++) {
            cout << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
