#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	--a, --b, --c;
	if (abs(a - b) * 2 <= c || abs(a - b)*2 <= a || abs(a - b) * 2 <= b) return void(cout << -1);
	cout << ((abs(a-b)+c)%(abs(a-b)*2))+1;
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