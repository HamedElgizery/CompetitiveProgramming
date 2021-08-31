#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 102;
vector<int> adj[mxN];
vector<pair<int, int>> ans[mxN];
bool vis[mxN];

int col = 1;
void dfs(int node) {
	if (vis[node]) return;
	vis[node] = 1;
	ans[node].push_back({node, col++});
	for (auto it : adj[node]) {
		ans[node].push_back({node, col});
		ans[it].push_back({it, col++});
	}
	for (auto it : adj[node])
		dfs(it);
}

void solve() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
		dfs(i);

	assert(col <= 5001);

	for (int i = 1; i <= N; i++) {
		cout<< ans[i].size() << '\n';
		for (auto it : ans[i]) 
			cout << it.first << ' ' << it.second << '\n';
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}