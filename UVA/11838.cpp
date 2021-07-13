#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e3;
vector<int> adj[N];
int id, ID[N], mnID[N];
bool inSt[N];
stack<int> st;
int cnt, n, m;;

int tarjan(int node) {
	ID[node] = mnID[node] = id++;
	st.push(node);
	inSt[node] = 1;

	for (auto c : adj[node]) {
		if (!(~ID[c])) tarjan(c);
		if (inSt[c]) mnID[node] = min(mnID[node], mnID[c]);
	}
	if (ID[node] == mnID[node]) {
		while(st.top() != node)
			inSt[st.top()] = 0, st.pop();
		inSt[st.top()] = 0;
		st.pop();
		cnt++;
	}
	return mnID[node];
}

void solve() {
	memset(ID, -1, sizeof ID);
	cnt = 0;
	for (int i = 0; i < n; i++)
		adj[i].clear();
	for (int i = 0; i < m; i++) {
		int u, v, p;
		cin >> u >> v >> p;
		--u, --v;
		adj[u].push_back(v);
		if (p == 2)
			adj[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		if (!(~ID[i]))
			tarjan(i);
	}

	cout << (cnt == 1) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n >> m && (n+m))
		solve();
}