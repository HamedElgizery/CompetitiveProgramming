#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll nCr(ll n) {
	return n * (n-1) / 2LL;
}

int n, d;

void solve() {
	cin >> n >> d;

	int A[n]; 
	for (int i = 0; i < n; i++) 
		cin >> A[i];

	ll ans = 0;
	int l = 0, r = 0;
	while(r < n) {
		while(abs(A[l] - A[r]) > d && l < r)
			l++;
		ans += nCr(r-l);
		r++;
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
	solve();
}