#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct DSU {
	int N;
	vector<int> SZ, P;
	DSU(int N) : N(N) {
		SZ.assign(N, 1);
		P.resize(N);
		for (int i = 0; i < N; i++) P[i] = i;
	}

	int parent(int a) {
		return P[a] = (P[a] == a ? a : parent(P[a])); 
	}

	bool unite(int a, int b) {
		a = parent(a);
		b = parent(b);
		if (a == b)
			return false;
		if (SZ[a] < SZ[b]) 
			swap(a, b);
		SZ[a] += SZ[b];
		P[b] = a;
		return true;
	}

	bool connected(int a, int b) {
		a = parent(a);
		b = parent(b);
		return a == b;
	}
};

void solve() {
	int N, M[2];
	cin >> N >> M[0] >> M[1];
	DSU d1(N+1), d2(N+1);
	for (int i = 0; i < M[0]; i++) {
		int u, v;
		cin >> u >> v;
		d1.unite(u, v);
	}
	for (int i = 0; i < M[1]; i++) {
		int u, v;
		cin >> u >> v;
		d2.unite(u, v);
	}
	vector<pair<int ,int>> ans;
	for (int i = 1; i <= N; i++) {
		for (int j = i+1; j <= N; j++) {
			if (!d1.connected(i, j) && !d2.connected(i, j)) {
				ans.push_back({i, j});
				d1.unite(i, j);
				d2.unite(i, j);
			}
		}
	}

	cout << ans.size() << endl;
	for (auto it : ans) {
		cout << it.first << ' ' << it.second << endl;
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