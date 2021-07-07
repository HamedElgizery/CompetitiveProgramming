#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	ll a, b, diff;
	cin >> a >> b;
	diff = abs(a-b);
	if (diff == 0) {
		cout << 0 << ' ' << 0;
		return;
	}
	cout << diff << ' ' << min(a%diff, diff-(a%diff));
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