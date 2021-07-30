// Implementation of Disjoint set union functions
// Complexity = O(4*alpha) ~ constant

void makeSet() {
	for(int i = 1; i <= n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}


int findParent(int node) {
	if(node == parent[node]) {
		return node;
	}
	// return findParent(parent[node]); // Not path compressed
	return parent[node] = findParent(parent[node]); // Path compressed
}


 void union(int u, int v) {
 	u = findParent(u);
 	v = findParent(v);

 	if(rank[u] < rank[v]) {
 		parent[u] = v;
 	}
 	else if(rank[v] < rank[u]) {
 		parent[v] = u;
 	}
 	else {
 		parent[v] = u;
 		rank[u]++;				// Rank will increase only if both have same rank
 	}
 }

int main(){

	vector<int> parent(100000), rank(100000);

	makeSet(); // initializes each node with parent as itself and rank as 0.

	// Operations

	int m;
	cin >> m;
	while(m--){
		int u, v;
		union(u, v);
	}

	// if u and v belong to the same component or not

	if(findParent(2) != findParent(3)) {
		cout << "Different component";
	}
	else{
		cout << "Same component";
	}
}