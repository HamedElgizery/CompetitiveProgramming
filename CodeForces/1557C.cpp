#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1e9+7, mxN = 2e5+100;
ll fact[mxN], inv[mxN], invfact[mxN];

ll N, K;

ll FP(ll x, ll y) {
	if (y == 0)
		return 1;
	ll tmp = FP(x, y>>1);
	return (((tmp*tmp)%MOD)*(y&1 ? x%MOD : 1))%MOD;
}

ll nCr(ll n, ll r) {
	return (fact[n] * ((invfact[r] * invfact[n-r])%MOD))%MOD;
}

void solve() {
	cin >> N >> K;
		
	ll f = 0;
	for (int i = 0; i <= N/2; ++i)
		f += nCr(N, 2*i);
	f += (N&1 ? 1 : -1);

	if (N&1) {
		cout << FP(f, K);
	}
	else {
		ll _2pw = FP(2, N);
		ll ans = FP(f, K);
		for (int i = 0; i < K; i++) {
			(ans += FP(_2pw, i) * FP(f, K - i - 1)) %= MOD;
		}
		cout << ans;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
	for (int i = 2; i < mxN; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
		inv[i] = MOD - (inv[MOD % i] * (MOD / i) % MOD);
		invfact[i] = (inv[i] * invfact[i - 1]) % MOD;
	}

	ll t;
	cin >> t;
	while(t--) {
		solve();
		cout << '\n';
	}
}
