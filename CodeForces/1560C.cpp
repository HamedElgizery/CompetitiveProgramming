#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll calc(ll mid) {
	return mid + (mid - 2) * (mid - 1);
}

void solve() {
	ll K;
	cin >> K;

	ll l = 1, r = 1e9, mid;
	while(l < r) {
		mid = (l + r + 1) >> 1;
		if (calc(mid) <= K) l = mid;
		else r = mid - 1; 
	}

	if (K >= calc(l) + l) {
		cout << l << ' ' << l - abs(K - (calc(l) + l - 1));
	}
	else {
		// cout << "d";
		cout << abs(K - calc(l)) + 1 <<  ' ' << l;
	}
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