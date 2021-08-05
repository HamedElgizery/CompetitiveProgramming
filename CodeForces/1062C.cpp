#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1e5+10, MOD = 1e9+7;

int N, Q;
int cum[mxN];

void solve() {
	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		char c;
		cin >> c;
		cum[i] += cum[i-1] + c - '0';
	}

	vector<ll> toISq(N+1, 0);
	toISq[1] = 1;

	ll powerOf2 = 1;
	for (int i = 2; i <= N; i++) {
		(powerOf2 *= 2) %= MOD;
		toISq[i] = toISq[i-1] + powerOf2;
		toISq[i] %= MOD;
	}

	while(Q--) {
		ll l, r;
		cin >> l >> r;
		ll ones = cum[r] - cum[l-1];
		ll ans = toISq[ones];
		ll zeros = (r - l + 1) - ones;
		ans += toISq[ones] * (toISq[zeros]);
		cout << ans % MOD << '\n';
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