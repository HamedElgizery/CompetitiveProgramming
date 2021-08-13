#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> A1, A2;
int N, M;

bool ok(ll mid) {
	int j = 0;
	for (int i = 0; i < M; i++) {
		if (abs(A2[i] - A1[j]) <= mid)
			j++;
		if (j == N)
			return 1;
	}

	return 0;
}

void solve() {
	cin >> N >> M;
	A1.resize(N); A2.resize(M);
	for (auto& a : A1) cin >> a;
	for (auto& a : A2) cin >> a;
	sort(A1.begin(), A1.end());
	sort(A2.begin(), A2.end());

	if (N > M) {
		swap(N, M);
		swap(A1, A2);
	}

	ll l = 0, r = 1e10, mid;
	while(l < r) {
		mid = (l+r)>>1;
		if (ok(mid)) r = mid;
		else l = mid+1;
	}
	cout << r << endl;
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