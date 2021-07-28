#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << 1;
		return;
	}
	string ans = "8426";
	cout << ans[(n+3)%4];
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