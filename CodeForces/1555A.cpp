#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


void solve() {
	ll N;
	cin >> N;
	cout << max(6LL, N+1) / 2 * 5;
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