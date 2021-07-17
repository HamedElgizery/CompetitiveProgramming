#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int M = 1e5+10;
int n, m;
vector<int> adj[M];
bool AP[M];
int parent[M], ID[M], low[M], id = 1;

void dfs(int node) {
	ID[node] = low[node] = id++;
	int childeren = 0;
	for (auto c : adj[node]) {
		if (!(~ID[c])) {
			childeren++;
			parent[c] = node; 
			dfs(c);
			low[node] = min(low[node], low[c]);
			if (!(~parent[node]) && childeren >= 2)
				AP[node] = 1;
			if (~parent[node] && low[c] >= ID[node])
				AP[node] = 1;
		}
		else if (parent[node] != c) {
			low[node] = min(low[node], ID[c]);
		}
	}
}


void solve() {
	id = 1;
	memset(parent, -1, sizeof(int) * (n+5));
	memset(ID, -1, sizeof(int) * (n+5));
	memset(low, -1, sizeof(int) * (n+5));
	memset(AP, 0, sizeof(int) * (n+5));
	for (int i = 1; i <= n; i++)
		adj[i].clear();

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	cout << count(AP+1, AP+n+1, 1) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n >> m && (n + m)) {
		solve();
	}
}