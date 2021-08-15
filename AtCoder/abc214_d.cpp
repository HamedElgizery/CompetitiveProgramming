#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct DSU {
	int N;
	vector<ll> SZ, P;

	DSU(int N) : N(N) {
		SZ.assign(N, 1);
		P.resize(N);
		for (int i = 1; i < N; i++) P[i] = i;
	}
	
	int parent(int a) {
		return P[a] = (P[a] == a ? a : parent(P[a]));
	}

	ll unite(int a, int b) {
		a = parent(a);
		b = parent(b);
		if (a == b)
			return 0;
		if (SZ[a] < SZ[b])
			swap(a, b);
		ll ret = SZ[a] * SZ[b];
		SZ[a] += SZ[b];
		P[b] = P[a];
		return ret;
	}

};

void solve() {
	int N;
	cin >> N;
	DSU d(N+1);
	vector<pair<ll ,pair<int, int>>>  edges;
	for (int i = 1; i < N; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w, {u, v}});
	}
	sort(edges.begin(), edges.end());
	long long ans = 0;

	for (auto& it : edges) {
		ans += d.unite(it.second.first, it.second.second) * it.first;
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
	solve();
}