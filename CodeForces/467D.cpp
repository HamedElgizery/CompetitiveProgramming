#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

pair<ll, ll> analyze(const string& s) {
	return {count(s.begin(), s.end(), 'r'), s.size()};
}
const ll M = 2e5+10,  OO = 0x3f3f3f3f;
string essay[M];
ll n, m, nid = 1;
map<string, ll> con;
map<ll, string> bug;
vector<ll> adj[M], DAG[M];
pair<ll, ll> Data[M], compData[M];
//Tarjan
ll ID[M], link[M], id = 1, st[M], inSt[M], stsize;

void extract(ll node) {
	while(1) {
		ll t = st[--stsize];
		inSt[t] = 0;
		link[t] = link[node];
		if (t == node) break;
	}
}

ll tarjan(ll node) {
	ID[node] = link[node] = id++;
	st[stsize++] = node, inSt[node] = 1;
	for (auto c : adj[node]) {
		if (!(~ID[c])) {
			tarjan(c);
			link[node] = min(link[node], link[c]);
		}
		else if (inSt[c]) {
			link[node] = min(link[node], ID[c]);
		}
	}

	if (ID[node] == link[node]) 
		extract(node);

	return link[node];
}

pair<ll, ll> dp[M];

pair<ll, ll> dfs(ll node) {
	if (dp[node].first != -1)
		return dp[node];

	pair<ll, ll> ret = compData[node];
	for (auto it : DAG[node]) {
		ret = min(ret, dfs(it));
	}
	return dp[node] = ret;
}

void solve() {
	memset(ID, -1, sizeof ID);
	memset(compData, OO, sizeof compData);
	memset(dp, -1, sizeof dp);
	cin >> m;
	for (ll i = 0; i < m; i++) {
		cin >> essay[i];
		transform(essay[i].begin(), essay[i].end(), essay[i].begin(), ::tolower);
		if (!con.count(essay[i]))
			con[essay[i]] = nid++;
	}

	cin >> n;
	for (ll i = 0; i < n; i++) {
		string u, v;
		cin >> u >> v;
		transform(u.begin(), u.end(), u.begin(), ::tolower);
		transform(v.begin(), v.end(), v.begin(), ::tolower);
		if (!con.count(u))
			con[u] = nid++;
		if (!con.count(v))
			con[v] = nid++;
		adj[con[u]].push_back(con[v]);
	}

	for (ll i = 1; i < nid; i++) {
		if (!(~ID[i]))
			tarjan(i);
	}

	for (auto it : con) {
		Data[it.second] = analyze(it.first);
	}

	for (ll i = 1; i < nid; i++) {
		compData[link[i]] = min(compData[link[i]], Data[i]);
	}
	for (ll i = 1; i < nid; i++) {
		for (auto c : adj[i]) {
			if (link[i] != link[c])
				DAG[link[i]].push_back(link[c]);
		}
	}


	for (ll i = 1; i < nid; i++) {
		dfs(link[i]);
	}


	pair<ll, ll> ans = {0, 0};
	for (ll i = 0; i < m; i++) {
		ans.first += dp[link[con[essay[i]]]].first;
		ans.second += dp[link[con[essay[i]]]].second;
	}
	cout << ans.first << ' ' << ans.second << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
}