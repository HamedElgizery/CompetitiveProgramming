#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int a, b;
	cin >> a >> b;
	if (a == b && a == 0) cout << 0;
	else if (abs(a - b) & 1) cout << -1;
	else {
		if (a == b) cout << 1;
		else cout << 2;
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