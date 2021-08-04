#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, ID;

struct DSU {
	int N;
	vector<int> SZ, P;

	DSU(int N) : N(N) {
		SZ.assign(N, 0);
		P.resize(N);
		for (int i = 0; i < N; i++) 
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
		P[b] = a;
		return true;
	}
};
 
int kruskal(vector<pair<int, pair<int, int>>>& edges) {
	sort(edges.begin(), edges.end());
	DSU d(N);
	int ret = 0;

	for (auto e : edges) {
		if (d.unite(e.second.first, e.second.second)) {
			ret += e.first;
		}
	}
	return ret;
}


void solve() {
	cin >> N;
	vector<pair<int, pair<int ,int>>> A(N); for (auto& a : A) cin >> a.second.first >> a.second.second, a.first = ID++;

	vector<pair<int, pair<int, int>>> edges;
	for (int j = 0; j < 2; j++) {
		if (j)
			sort(A.begin(), A.end(), [](pair<int ,pair<int, int>> f, pair<int, pair<int, int>> s){
				return f.second.first < s.second.first;
			});
		else 
			sort(A.begin(), A.end(), [](pair<int ,pair<int, int>> f, pair<int, pair<int, int>> s){
				return f.second.second < s.second.second;
			});

		for (int i = 0; i+1 < N; i++) {
			edges.push_back({min(abs(A[i+1].second.first - A[i].second.first), abs(A[i+1].second.second - A[i].second.second)), {A[i].first, A[i+1].first}});
		}
	}
	cout << kruskal(edges);
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