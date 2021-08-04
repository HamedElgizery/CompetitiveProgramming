#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct DSU {
	int N;
	vector<int> SZ, P;

	DSU(int N) {
		N += 10;
		this->N = N;
		SZ.assign(N, 0);
		P.resize(N);
		for (int i = 1; i < N; i++) {
			P[i] = i;
		}
	}

	int parent(int a) {
		return P[a] = (P[a] == a ? a : parent(P[a]));
	}

	bool unite(int a, int b) {
		a = parent(a);
		b = parent(b);

		if (a == b)
			return 1;
		if (SZ[a] < SZ[b])
			swap(a, b);
		SZ[a] += SZ[b];
		P[b] = a;
		return 0;
	}
};

void solve() {
	int N, K;
	cin >> N >> K;

	DSU d(N);
	int ans = 0;

	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		ans += d.unite(x, y);
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