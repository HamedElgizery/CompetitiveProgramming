#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 150;

struct DSU {
	int N;
	vector<int> P;

	DSU(int N) : N(N) {
		P.resize(N);
		for (int i = 0; i < N; i++)
			P[i] = i;
	}

	int getParent(int a) {
		return P[a] = (P[a] == a ? a : getParent(P[a]));
	}

	void unite(int a, int b) {
		a = getParent(a);
		b = getParent(b);
		P[a] = b;
	}
};

DSU d(mxN);

bool query(int l, int r, int x) {
	set<int> st;
	st.insert(d.getParent(x));
	cout << (r-l+2) << ' ' << x+1;
	for (int i = l; i <= r; i++)
		cout << ' ' << i+1, st.insert(d.getParent(i));
	cout << endl;
	int res;
	cin >> res;
	return res == st.size();
}

int ID[mxN];

void solve() {
	int N, id = 1;
	cin >> N;	  

	for (int i = 1; i < N; i++) {
		if (query(0, i-1, i))
			continue;
		int l = 0, r = i-1, mid;
		while(l < r) {
			mid = (l+r)>>1;
			if (query(0, mid, i))
				l = mid+1;
			else
				r = mid;
		}
		d.unite(l, i);
	}
		
	vector<int> ans(N);
	for (int i = 0; i < N; i++) {
		if (!ID[d.getParent(i)])
			ID[d.getParent(i)] = id++;
		ans[i] = ID[d.getParent(i)];
	}
	cout << 0;
	for (auto &it : ans) cout << ' ' << it;
	cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
	return 0;
}