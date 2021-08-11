#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 2e5+10;
pair<int, int> RANGE[mxN];
int A[mxN];
int seg[mxN*4];

void build(int node, int l, int r) {
	if (l == r)  {

		return void(seg[node] = A[l]);
	}

	int mid = (l+r)>>1;

	build(node*2, l, mid);
	build(node*2+1, mid+1, r);

	seg[node] = min(seg[node*2], seg[node*2+1]);
}

int query(int node, int l, int r, int lt, int rt) {
	if (lt > r || rt < l) return INT_MAX;
	if (lt <= l && r <= rt) return seg[node];

	int mid = (l+r)>>1;

	return min(query(node*2, l, mid, lt, rt), query(node*2+1, mid+1, r, lt, rt));
}

void solve() {
	int N, Q;
	cin >> N >> Q;

	for (int i = 1; i <= Q; ++i) {
		RANGE[i].first = INT_MAX;
		RANGE[i].second = INT_MIN;
	}

	A[0] = 0;
	int ZER = -1, QFREQ = 0;
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
		if (!A[i]) ZER = i;
		if (A[i] == Q) QFREQ++;
	}

	for (int i = 1; i <= N; ++i) {
		if (!A[i]) {
			if (A[i-1])
				A[i] = A[i-1];
		}
	}

	for (int i = N; i ; --i) {
		if (!A[i]) {
			if (A[i+1])
				A[i] = A[i+1];
		}
	}

	for (int i = 1; i <= N; ++i) {
		if (!A[i]) A[i] = Q;
	}

	for (int i = 1; i <= N; ++i) {
		RANGE[A[i]].first = min(RANGE[A[i]].first, i);
		RANGE[A[i]].second = max(RANGE[A[i]].second, i);
	}

	build(1, 1, N);

	bool ans = 1;
	for (int i = 1; i <= Q; i++) {
		if (RANGE[i].second > 0) {
			ans &= (query(1, 1, N, RANGE[i].first, RANGE[i].second) >= i);
		}
	}

	if (!QFREQ && ~ZER) {
		A[ZER] = Q;
	}

	if (ans && (QFREQ || ~ZER)) {
		cout << "YES\n";
		for (int i = 1; i <= N; ++i) 
			cout << A[i] << ' ';
	}
	else {
		cout << "NO\n";
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