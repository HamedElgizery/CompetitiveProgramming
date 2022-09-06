#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	ll N, H;
	cin >> N >> H;
	vector<ll> A(N); for (auto &a : A) cin >> a;
	sort(A.rbegin(), A.rend());

	ll ans = 1e18;
	ans = min(ans, 2LL * ((H + A[0] + A[1] - 1) / (A[0] + A[1])));
	ans = min(ans, 2LL * ((max(0LL, H - A[0]) + A[0] + A[1] - 1) / (A[0] + A[1])) + 1);

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
	return 0;
}