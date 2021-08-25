#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("microbus.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		long long c, p, n;
		cin >> c >> p >> n;
		if(c-p>=n)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}