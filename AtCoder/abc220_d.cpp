#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 998244353;


void solve() {
	ll N;
	cin >> N;
	
	vector<int> A(N);
	for (auto &a : A) cin >> a;
	vector<vector<ll>> dp(10, vector<ll>(N, 0));
	dp[A[0]][0] = 1;

	for (int i = 1; i < N; i++) {
		for (int k = 0; k < 10; k++) {
			(dp[(A[i]*k)%10][i] += dp[k][i-1]) %= MOD;
			(dp[(A[i]+k)%10][i] += dp[k][i-1]) %= MOD;
		}
	}

	for (int k = 0; k < 10; k++) {
		cout << dp[k].back() << '\n';
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
	return 0;
}