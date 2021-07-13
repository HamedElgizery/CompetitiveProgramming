#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e3;
vector<int> adj[N];
int compID[N],id, n, ID[N], mnID[N], inDeg[N];
bool inSt[N];
stack<int> st;
vector<vector<int>> comps;

int tarjan(int node) {
	ID[node] = mnID[node] = id++;
	st.push(node);
	inSt[node] = 1;
	for (auto c : adj[node]) {
		if (!(~ID[c])) {
			tarjan(c);
		}
		if (inSt[c])
			mnID[node] = min(mnID[node], mnID[c]);
	}
	if (ID[node] == mnID[node]) {
		vector<int> comp;
		while(1) {
			comp.push_back(st.top());
			inSt[st.top()] = 0;
			compID[st.top()] = mnID[node];
			st.pop();
			if (comp.back() == node)
				break;
		}
		comps.push_back(comp);
	}
	return mnID[node];
}

struct mine {
	int x, y, d;
	int mnx, mxx, mny, mxy;
	mine() {}
	mine(int x, int y, int d) : x(x), y(y), d(d) {
		mnx = x - d/2;
		mxx = x + d/2;
		mny = y - d/2;
		mxy = y + d/2;
	}

	bool inRange(const mine& m) const {
		return m.x >= mnx && m.x <= mxx && m.y >= mny && m.y <= mxy;
	}
} mines[N];

void solve() {
	comps.clear();
	memset(ID, -1, sizeof ID);
	memset(inDeg, 0, sizeof inDeg);
	memset(mnID, -1, sizeof mnID);
	memset(compID, 0, sizeof compID);
	id = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		mines[i] = mine(x, y, d);
		adj[i].clear();
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (mines[i].inRange(mines[j]))
				adj[i].push_back(j);
			if (mines[j].inRange(mines[i]))
				adj[j].push_back(i);
		}
	}

	for (int i = 0; i < n; i++)
		if (!(~ID[i]))
			tarjan(i);

	int ans = comps.size();
	for (int i = 0; i < n; i++) {
		for (auto c : adj[i]) {
			int compu = compID[i];
			int compv = compID[c];

			if (compu == compv)
				continue;
			if (!inDeg[compv]++) ans--;
		}
	}
	cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
}