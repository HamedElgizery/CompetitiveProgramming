#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+10;
int n, m;
int st[N], stSize, ID[N], lowLink[N], id, outD[N];
bool inSt[N];
vector<int> adjF[N];
vector<vector<int>> comps;

int tarjan(int node) {
	ID[node] = lowLink[node] = id++;
	st[stSize++] = node;
	inSt[node] = 1;

	for (auto it : adjF[node]) {
		if (!(~ID[it])) {
			tarjan(it);
			lowLink[node] = min(lowLink[node], lowLink[it]);
		}
		else if(inSt[it]) {
			lowLink[node] = min(lowLink[node], ID[it]);
		}
	}

	if (ID[node] == lowLink[node]) {
		vector<int> comp;
		comp.push_back(node);
		while(st[stSize-1] != node)
			comp.push_back(st[stSize-1]), lowLink[st[stSize-1]]=lowLink[node], inSt[--stSize] = 0;
		inSt[--stSize] = 0;
		comps.push_back(comp);
	}
	return lowLink[node];
}

void solve() {
	memset(ID, -1, sizeof ID);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adjF[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (!(~ID[i]))
			tarjan(i);
	}
	for (int i = 1; i <= n; i++) {
		for (auto it : adjF[i]) {
			if (lowLink[it] != lowLink[i])
				outD[lowLink[i]]++;
		}
	}

	vector<int> ans;
	int first = -1, p = 1;
	for (int i = 1; i <= n; i++) {
		if (!outD[lowLink[i]]) {
			if(first == -1)
				first = lowLink[i];
			else
				if (first != lowLink[i])
					p = 0;
			ans.push_back(i);
		}
	}
	if(!p)
		ans.clear();
	cout << ans.size() << endl;
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