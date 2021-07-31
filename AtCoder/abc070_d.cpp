#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1e5+10;
ll dist[mxN], N;
vector<pair<int, ll>> adj[mxN];

void dfs(int node, ll len) {
	if (~dist[node])
		return;

	dist[node] = len;
	for (auto c : adj[node]) {
		dfs(c.first, len + c.second);
	}
}


void solve() {
	memset(dist, -1, sizeof dist);

	cin >> N;

	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	
	int Q, K;
	cin >> Q >> K;
	dfs(K, 0);

	while(Q--) {
		int x, y;
		cin >> x >> y;
		cout << dist[x] + dist[y] << '\n';
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