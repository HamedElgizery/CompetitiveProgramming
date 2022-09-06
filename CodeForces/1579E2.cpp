#include <bits/stdc++.h>

using namespace std;

struct BIT {
	int N;
	vector<int> bit;
	BIT(int N) {
		this->N = N+2;
		bit.assign(this->N, 0);
	}

	void add(int idx, int delta) {
		for (; idx < N; idx += idx & -idx)
			bit[idx] += delta;
	}

	int query(int idx) {
		int ret = 0;
		for (; idx > 0; idx -= idx & -idx)
			ret += bit[idx];
		return ret;
	}

};


void solve() {
	int N;
	cin >> N;
	vector<int> A(N); for (auto &a : A) cin >> a;
	int id = 1;
	map<int, int> IDI, IDD;
	vector<int> B = A;
	sort(B.begin(), B.end());
	for (auto it : B) {
		if (!IDI[it])
			IDI[it] = id++;
	}
	id = 1;
	sort(B.rbegin(), B.rend());
	for (auto it : B) {
		if (!IDD[it])
			IDD[it] = id++;
	}
	BIT I(id), D(id);
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		ans += min(I.query(IDI[A[i]]-1), D.query(IDD[A[i]]-1));
		I.add(IDI[A[i]], 1);
		D.add(IDD[A[i]], 1);
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
	while(t--) {
		solve(); 
		cout << "\n";
	}
	return 0;
}
