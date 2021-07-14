#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int n, m, id, ID[N], mnID[N], freq[N];
stack<int> st;
bool inSt[N];
vector<int> adj[N];

bool pop(int node, int mn) {
	int ret = st.top() != node;
	mnID[st.top()] = mn;
	inSt[st.top()] = 0;
	st.pop();
	return ret;
}

int tarjan(int node) {
	ID[node] = mnID[node] = id++;
	st.push(node);
	inSt[node] = 1;
	for (auto c : adj[node]) {
		if (!(~ID[c])) {
			tarjan(c);
			mnID[node] = min(mnID[node], mnID[c]);
		}
		if (inSt[c]) mnID[node] = min(mnID[node], ID[c]);
	}
	if (ID[node] == mnID[node])
		while(pop(node, mnID[node]))
			continue;
	freq[mnID[node]]++;
	return mnID[node];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	memset(ID, -1, sizeof ID);
	
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
	}

	for (int i = 0; i < n; i++)
		if (!(~ID[i])) tarjan(i);

	string blank = "";
	for (int i = 0; i < n; i++) {
		cout << blank << (freq[mnID[i]] > 1);
		blank = " ";
	}
}