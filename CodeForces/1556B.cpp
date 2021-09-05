#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll minTo(vector<int> x, vector<int> y) {
	if (count(x.begin(), x.end(), 1) != count(y.begin(), y.end(), 1))
		return LLONG_MAX;
	ll ret = 0;
	vector<int> v1, v2;
	for (int i = 0; i < x.size(); i++) {
		if (x[i]) v1.push_back(i);
		if (y[i]) v2.push_back(i);
	}
	for (int i = 0; i < v1.size(); i++)
		ret += abs(v1[i] - v2[i]);
	return ret;
}

void solve() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (auto& a : A) {
		cin >> a;
		a &= 1;
	}
	vector<int> v1, v2;
	for (int i = 0; i < N; i++) {
		v1.push_back(i&1);
		v2.push_back(i&1^1);
	}
	ll ans = min(minTo(v1, A), minTo(v2, A));
	if (ans == LLONG_MAX) {
		cout << -1;
		return;
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
		cout << '\n';
	}
}