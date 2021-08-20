#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1e5+10;
int N;
int RANGE[2][mxN];
vector<int> adj[mxN];
ll dp[2][mxN];

void dfs(int node, int parent = -1) {
	dp[0][node] = dp[1][node] = 0;
	for (auto& c : adj[node]) {
		if (c == parent) continue;
		dfs(c, node);
		dp[0][node] += max(dp[0][c] + abs(RANGE[0][c] - RANGE[0][node]), dp[1][c] + abs(RANGE[1][c] - RANGE[0][node]));
		dp[1][node] += max(dp[0][c] + abs(RANGE[0][c] - RANGE[1][node]), dp[1][c] + abs(RANGE[1][c] - RANGE[1][node]));
	}
}

void solve() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> RANGE[0][i] >> RANGE[1][i];
		adj[i].clear();
	}

	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	cout << max(dp[0][1], dp[1][1]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << '\n';
	}
}