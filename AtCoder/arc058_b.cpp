#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mxN = 2e5+10, MOD = 1e9 + 7;
ll fact[mxN];
ll H, W, A, B;

ll FB(ll x, ll y) {
	if (y == 0)
		return 1;
	ll tmp = FB(x, y>>1);
	return (((tmp*tmp)%MOD)*(y&1 ? x : 1))%MOD;
}
 
ll nCr(ll n, ll r) {
	return (fact[n] * FB((fact[r] * fact[n-r])%MOD, MOD-2))%MOD;
}

void solve() {
	cin >> H >> W >> A >> B;

	ll ans = 0;
	for (ll i = 0; i <= H-A-1; i++) {
		ans += (nCr(B+i-1, i)*nCr(W-B+H-i-2, H-i-1))%MOD;
		ans %= MOD;
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
	fact[0] = fact[1] = 1;
	for (ll i = 2; i < mxN; i++)
		(fact[i] = fact[i-1] * i)%=MOD;
	solve();
}
