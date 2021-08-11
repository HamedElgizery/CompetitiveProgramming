#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1e5+10;
vector<int> adj[mxN];
int N, S;

void solve() {
	cin >> N >> S;
	for (int i = 0; i < N-1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int cnt = 0;
	for (int i = 1; i <= N; ++i)
		cnt += adj[i].size() == 1;

	cout << fixed << setprecision(15) << (S*2.0/cnt); 
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