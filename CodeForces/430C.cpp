#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mxN = 1e5+1;
vector<int> adj[mxN];
int cur[mxN], goal[mxN];
vector<int> ans;
void dfs(int node, int p, int cr, int nx) {
	if ((cur[node-1]^cr) != goal[node-1]) {
		ans.push_back(node);
		cr^=1;
	}
	for (auto c : adj[node]) {
		if (p == c)
			continue;
		dfs(c, node, nx, cr);
	}
}

void solve() {
	int N;
	cin >> N;

	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < N; i++)
		cin >> cur[i];
	for (int i = 0; i < N; i++)
		cin >> goal[i];

	dfs(1, -1, 0, 0);
	cout << ans.size() << endl;
	for (auto it : ans) {
		cout << it << '\n';
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