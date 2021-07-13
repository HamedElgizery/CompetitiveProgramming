#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6+10;

set<int> adjF[N], adjC[N];
ll id, rid, ID[N], mnID[N], fun[N], compFun[N];
stack<int> st;
bool inSt[N];
ll ans = LLONG_MIN, n, m, s, e;
vector<vector<int>> comps;

int tarjan(int node) {
	ID[node] = mnID[node] = id++;
	inSt[node] = 1;
	st.push(node);

	for (auto c : adjF[node]) {
		if (!(~ID[c])) tarjan(c);
		if (inSt[c]) mnID[node] = min(mnID[node], mnID[c]);
	}

	int mnid = mnID[node];
	if (ID[node] == mnID[node]) {
		vector<int> comp;
		while(st.top() != node) {
			compFun[rid] += fun[st.top()]; 
			comp.push_back(st.top());
			inSt[st.top()] = 0;
			mnID[st.top()] = rid;
			st.pop();
		}
		compFun[rid] += fun[st.top()];
		comp.push_back(st.top());
		inSt[st.top()] = 0;
		mnID[st.top()] = rid;
		st.pop();
		rid++;
		comps.push_back(comp);
	}
	return mnid;
}

bool vis[N];
void dfs(int node, ll sum) {

	if (node == mnID[e]) return void(ans = max(ans, sum));
	for (auto it : adjC[node]) {
		dfs(it, sum + compFun[it]);
	}
}

void solve() {
	memset(ID, -1, sizeof ID);
	cin >> n >> m >> s >> e; 
	--s, --e;
	for (int i = 0; i < n; i++)
		cin >> fun[i];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adjF[u].insert(v);
	}

	for (int i = 0; i < n; i++) {
		if (!(~ID[i])) tarjan(i);
	}

	for (int i = 0; i < n; i++) {
		for (auto it : adjF[i]) {
			if (mnID[i] != mnID[it]) {
				adjC[mnID[i]].insert(mnID[it]);
			}
		}
	}
	dfs(mnID[s], compFun[mnID[s]]);
	cout << ans << endl;
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