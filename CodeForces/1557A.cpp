#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N;
	cin >> N;

	ll sumA = 0;
	vector<ll> A(N); for (auto& a : A) cin >> a, sumA += a;

	sort(A.begin(), A.end());
	double ans = LLONG_MIN;
	ll sumB = 0;
	for (ll i = 0; i < N; i++) {
		sumB += A[i];
		ans = max(ans, (sumA - sumB)*1.0/(N-(i+1)) + (sumB)*1.0/(i+1));
	}

	cout << fixed << setprecision(12) << ans;
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