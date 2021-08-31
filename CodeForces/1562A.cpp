#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int l, r;
	cin >> l >> r;
	int mid = (r+1) / 2;
	int ans = INT_MIN;

	for (int i = max(l, mid - 100); i <= min(r, max(l,mid)+100); i++) {
		ans = max(ans, r % i);
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
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << '\n';
	}
}