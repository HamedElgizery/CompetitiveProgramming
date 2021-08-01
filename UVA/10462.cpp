#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<pair<int, int>, pair<int ,int>> edge;

struct DSU {
	int N, cntGroups;
	vector<int> SZ, P;

	DSU(int N) : N(N) {
		SZ.assign(N, 1);
		P.resize(N);
		for (int i = 0; i < N; i++) P[i] = i;
		cntGroups = N;
	}

	int parent(int a) {
		return P[a] = (P[a] == a ? a : parent(P[a]));
	}

	bool unite(int a, int b) {
		a = parent(a);
		b = parent(b);
		if (a == b) return false;
		if (SZ[a] < SZ[b])
			swap(a, b);

		SZ[a] += SZ[b]; 
		P[b] = a;
		cntGroups--;
		return true;
	}

};

vector<edge> EDGES;
int U, E;

bool connected(DSU& d) {
	return d.cntGroups == 1;
}

pair<bool, vector<edge>> best(int skip) {
	vector<edge> choosen;
	DSU d(U);
	for (auto e : EDGES) {
		if (e.first.second == skip)
			continue;
		if (d.unite(e.second.first, e.second.second)) {
			choosen.push_back(e);
		}
	}
	if (connected(d))
		return {1, choosen};
	return {0, choosen};
}

int cost(vector<edge> choosen) {
	int ret = 0;
	for (auto e : choosen)
		ret += e.first.first;
	return ret;
}

void solve() {
	EDGES.clear();
	cin >> U >> E;

	for (int i = 0; i < E; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		EDGES.push_back({{c, i}, {--u, --v}});
	}

	sort(EDGES.begin(), EDGES.end());

	pair<bool, vector<edge>> Best = best(-1);
	if (!Best.first) {
		cout << "No way";
		return;
	}
	int ans = INT_MAX;
	for (auto e : Best.second) {
		pair<bool, vector<edge>> tmp = best(e.first.second);
		if (tmp.first) {
			int c = cost(tmp.second);
			ans = min(ans, c);
		}
	}

	if (ans == INT_MAX) {
		cout << "No second way";
		return;
	}

	cout << ans;
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
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << " : ";
		solve();
		cout << '\n';
	}
}