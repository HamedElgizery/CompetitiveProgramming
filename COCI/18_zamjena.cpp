#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 5e4+10;
int N;
string A1[mxN], A2[mxN];
bool ans = 1;

bool is_number(string& s) {
	return '0' <= s[0] && s[0] <= '9'; 
}

struct DSU {
	int N;
	vector<int> SZ, P;
	vector<set<string>> cntEq;

	DSU(int N) {
		N++;
		this->N = N;
		SZ.assign(N, 1);
		P.resize(N);
		cntEq.assign(N, set<string>());
		for (int i = 0; i < N; i++) P[i] = i;
	}

	int getParent(int a) {
		return P[a] = (P[a] == a ? a : getParent(P[a]));
	}

	bool unite(int a, int b) {
		a = getParent(a);
		b = getParent(b);

		if (a == b)
			return false;

		if (SZ[a] < SZ[b])
			swap(a, b);

		SZ[a] += SZ[b];
		P[b] = a;

		return true;
	}

};

map<string, int> ID;
int id = 1;

void solve() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A1[i];
		if (!is_number(A1[i])) {
			if (!ID[A1[i]]) {
				ID[A1[i]] = id++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> A2[i];
		if (!is_number(A2[i])) {
			if (!ID[A2[i]]) {
				ID[A2[i]] = id++;
			}
		}
		if (is_number(A1[i]) && is_number(A2[i]) && A1[i] != A2[i])
			ans = 0;
	}

	if (!ans) return void(cout << "NE\n");

	DSU d(id);
	for (int i = 0; i < N; i++) {
		if (!is_number(A1[i]) && !is_number(A2[i]))
			d.unite(ID[A1[i]], ID[A2[i]]);
	}

	for (int i = 0; i < N && ans; ++i) {
		if (!is_number(A1[i]) && is_number(A2[i])) {
			d.cntEq[d.getParent(ID[A1[i]])].insert(A2[i]);
			if (d.cntEq[d.getParent(ID[A1[i]])].size() > 1)
				ans = 0;
		}
		if (is_number(A1[i]) && !is_number(A2[i])) {
			d.cntEq[d.getParent(ID[A2[i]])].insert(A1[i]);
			if (d.cntEq[d.getParent(ID[A2[i]])].size() > 1)
				ans = 0;
		}
	}

	cout << (ans ? "DA" : "NE") << endl;
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