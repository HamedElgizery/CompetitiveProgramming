#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("money.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		long long x, y;
		cin >> x >> y;
		cout << (y / x) + bool(y%x) << endl;
	}
}