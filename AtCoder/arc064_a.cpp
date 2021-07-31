#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	ll N, X;
	cin >> N >> X;
	vector<ll> A(N); for (auto& a : A) cin >> a;
	A.push_back(0);

	ll ans = 0;
	for (int i = 1; i < N; i++) {
		ll left = max(0LL,(A[i] + A[i-1]) - X);
		ll right = max(0LL, (A[i] + A[i+1]) - X);
		ll rem = min({A[i], left, right});
		ans += rem;
		A[i] -= rem;
		left = max(0LL, (A[i] + A[i-1]) - X);
		right = max(0LL, (A[i] + A[i+1]) - X);
		ans += left+right;
		A[i-1] -= left;
		A[i+1] -= right;
	}

	cout << ans ;
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