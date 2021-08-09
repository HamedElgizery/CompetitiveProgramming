#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 2e5;
int ans[mxN+1];

struct DSU {
	int N;
	vector<int> SZ, P;

	DSU(int N) {
		this->N = ++N;
		SZ.assign(N, 1);
		P.resize(N);
		for (int i = 1; i < N; i++)
			P[i] = i;
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
		P[b] = P[a];

		return true;
	}

	int getSize(int a) {
		return SZ[parent(a)];
	}
};


void solve() {
	int N, K, L;
	cin >> N >> K >> L;

	DSU d1(N), d2(N);
	for (int i = 0; i < K; i++) {
		int u, v;
		cin >> u >> v;
		d1.unite(u, v);
	}

	for (int i = 0; i < L; i++) {
		int u, v;
		cin >> u >> v;
		d2.unite(u, v);
	}

	map<pair<int, int>, int> freq;

	for (int i = 1; i <= N; i++)
		freq[{d1.parent(i), d2.parent(i)}]++;


	for (int i = 1; i <= N; i++) {
		cout << freq[{d1.parent(i), d2.parent(i)}] << ' ';
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