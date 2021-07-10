#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5;

/*
	applying topological sort
*/

int n, k;
int parent[N];
bool vis[N];
vector<int> adj[N];
vector<int> top;

void dfs(int node) {
	if (vis[node])
		return;
	vis[node] = 1;

	for (auto it : adj[node])
		dfs(it);

	top.push_back(node);
}


void solve() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int w;
		cin >> w;
		for (int j = 0; j < w; j++) {
			int stud;
			cin >> stud;
			--stud;
			adj[i].push_back(stud);
		}
	}
	for (int i = 0; i < n; i++) {
		dfs(i);
	}

	int p = -1;
	for (int i = n-1; i >= 0; i--) {
		parent[top[i]] = p+1;
		p = top[i];
	}
	for (int i = 0; i < n; i++) {
		cout << parent[i] << '\n';
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