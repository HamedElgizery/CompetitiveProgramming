#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN=2e6+100, MOD = 1e9+7;
ll fact[mxN];

ll FP(ll x, ll y) {
	if (y == 0)
		return 1;
	ll tmp = FP(x, y>>1);
	return (((tmp*tmp)%MOD)*(y&1 ? x : 1))%MOD;
}

ll nCr(ll n, ll r) {
	return (fact[n] * FP((fact[r] * fact[n-r]) % MOD, MOD-2))%MOD;
}

ll calculate(int r, int c) {
	ll ret = 0;
	for (int i = 0; i <= r; i++) {
		(ret += nCr(i + c + 1, i+1)) %= MOD;
	}
	return ret;
}

void solve() {
	fact[0] = fact[1] = 1;

	for (int i = 2; i < mxN; i++) {
		fact[i] = fact[i-1] * i;
		fact[i] %= MOD;
	}
	int r1, r2, c1, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	if (r1 < r2)
		swap(r1, r2);
	if (c1 < c2)
		swap(c1, c2);

	ll ans = calculate(r1, c1) + calculate(r2-1, c2-1) - calculate(r2-1, c1) - calculate(r1, c2-1);

	while(ans < 0)
		ans += MOD;
	cout << ans % MOD << endl;
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