#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
	Since every student has at most two archenemies, 
	then it can be seen that we will have a forest 
	of simple cycles and chains, so we just have to 
	check for every connected component if it's Bipartite
	if so, then we don't have two remove any student from that component
	else, we need to remove one,
	also we need to check after counting the min number of students to be removed
	if the remaining students are divisible by two if no we remove one more 
*/


const int N = 100;
int n, m;
int color[N];
vector<int> adj[N];
int ans = 0;

bool notBip(int node, int c, int p) {
	if (~color[node]) {
		return c != color[node];
	}

	color[node] = c;
	bool ret = false;
	for (auto it : adj[node]) {
		if (it != p)
			ret |= notBip(it, 1-c, p);
	}
	return ret;
}

void solve() {
	cin >> n >> m;
	memset(color, -1, sizeof color);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < n; i++)
		if (color[i] == -1)
			ans += notBip(i, 0, -1);
	

	cout << ans + (n-ans)%2;
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