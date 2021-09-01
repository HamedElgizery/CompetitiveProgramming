#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mxN = 3e5+10;
int N, M;
set<int> adj[mxN];
set<int> edgesVal;
int val[mxN], color[mxN];
set<int> ans;

bool dfs(int node, int p, int c) {
	if (~color[node]) {
		if (c != color[node])
			return false;
		return true;
	}
	bool ret = 1;
	color[node] = c;
	if (c == 1)
		ans.insert(node);
	for (auto it : adj[node]) {
		if (it != p && ((val[node] ^ val[it]) == 0)) {
			ret &= dfs(it, node, 1 - c);
		}
	}
	return ret;
}

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> val[i];
	}

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
		edgesVal.insert(val[u] ^ val[v]);
	}

	int mex = 0;
	for (auto it : edgesVal) {
		if (it != mex) {
			break;
		}
		mex++;
	}

	bool good = 1;
	memset(color, -1, sizeof color);
	for (int i = 1; i <= N; i++) {
		if (color[i] == -1)
			good &= dfs(i, -1, 0);
	}
	if (!good) return void(cout << -1);
	cout << ans.size() << ' ' << mex << endl;
	for (auto it : ans) {
		cout << it << ' ';
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